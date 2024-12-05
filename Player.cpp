#include "Player.h"
#include "raymath.h"

Player::Player() : position{ 400, 300 }, speed{ 200.0f } {}

Player::~Player() {
    if (playerTexture.id != 0) {
        UnloadTexture(playerTexture);
    }
}

void Player::handleInput(float dt) {
    Vector2 direction = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_D)) direction.x += 1.0f;
    if (IsKeyDown(KEY_A)) direction.x -= 1.0f;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0f;
    if (IsKeyDown(KEY_S)) direction.y += 1.0f;

    if (direction.x != 0.0f || direction.y != 0.0f) {
        direction = Vector2Normalize(direction);
    }

    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;

    if (IsKeyDown(KEY_E)) {
        rotation += 100.0f * dt;
    }
    if (IsKeyDown(KEY_Q)) {
        rotation -= 100.0f * dt;
    }
}

void Player::update(float dt) {

}

void Player::draw() const {
    if (playerTexture.id != 0) {
        Rectangle sourceRect = { 0, 0, static_cast<float>(playerTexture.width), static_cast<float>(playerTexture.height) };
        Rectangle destRect = { position.x, position.y, static_cast<float>(size), static_cast<float>(size) };
        Vector2 origin = { static_cast<float>(size) / 2, static_cast<float>(size) / 2 };
        DrawTexturePro(playerTexture, sourceRect, destRect, origin, rotation, WHITE);
    }
    else {
        Rectangle rect = { position.x, position.y, static_cast<float>(size), static_cast<float>(size) };
        Vector2 origin = { static_cast<float>(size) / 2, static_cast<float>(size) / 2 };
        DrawRectanglePro(rect, origin, rotation, BLUE);
    }
}

void Player::setTexture(Texture2D newTexture) {
    playerTexture = newTexture;
}