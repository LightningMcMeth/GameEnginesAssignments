#include "GameLogic.h"

void GameLogic::readInput() {

    if (IsKeyPressed(KEY_Q)) {
        CloseWindow();
    }

    if (IsKeyPressed(KEY_P)) {
        isPaused = !isPaused;
    }

    if (IsKeyPressed(KEY_ONE)) {
        gameSaver.saveGameState(player);
    }

    if (IsKeyPressed(KEY_TWO)) {
        gameSaver.loadGameState(player);
    }

    if (!isPaused) {
        player.handleInput(dt);
    }
}

void GameLogic::update() {
    if (!isPaused) {
        player.update(dt);

        checkPlayerCollisionWithBorder();
    }
}

void GameLogic::checkPlayerCollisionWithBorder() {

    float halfPlayerSize = player.getSize() / 2.0f;
    if (player.getPosition().x - halfPlayerSize < 0) player.setPositionX(halfPlayerSize);
    if (player.getPosition().x + halfPlayerSize > screenWidth) player.setPositionX(screenWidth - halfPlayerSize);
    if (player.getPosition().y - halfPlayerSize < 0) player.setPositionY(halfPlayerSize);
    if (player.getPosition().y + halfPlayerSize > screenHeight) player.setPositionY(screenHeight - halfPlayerSize);
}

void GameLogic::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    player.draw();

    if (isPaused) {
        DrawText("Game Paused", screenWidth / 2 - 60, screenHeight / 2, 20, RED);
    }


    EndDrawing();
}

void GameLogic::run() {
    initialize();

    while (!WindowShouldClose()) {
        dt = GetFrameTime();

        readInput();
        update();
        render();
    }

    CloseWindow();
}

void GameLogic::initialize() {
    InitWindow(screenWidth, screenHeight, "Big Gaming");
    SetTargetFPS(targetFPS);

    assetSetter.loadAndSetPlayerTexture(player, assetLoader);
}