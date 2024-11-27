#include "Player.h"
#include "raymath.h"

Player::Player() : position{ 400, 300 }, speed{ 200.0f } {}

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
}


void Player::update(float dt) {

}

void Player::draw() const {
    DrawRectangleV(position, { static_cast<float>(size), static_cast<float>(size) }, BLUE);
}