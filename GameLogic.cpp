#include "GameLogic.h"

void GameLogic::readInput() {

    if (IsKeyPressed(KEY_Q)) {
        CloseWindow();
    }

    if (IsKeyPressed(KEY_P)) {
        isPaused = !isPaused;
    }

    if (!isPaused) {
        player.handleInput(dt);
    }
}

void GameLogic::update() {
    if (!isPaused) {
        player.update(dt);

        if (player.getPosition().x < 0) player.setPositionX(0);
        if (player.getPosition().x + player.getSize() > screenWidth) player.setPositionX(screenWidth - player.getSize());
        if (player.getPosition().y < 0) player.setPositionY(0);
        if (player.getPosition().y + player.getSize() > screenHeight) player.setPositionY(screenHeight - player.getSize());
    }
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
    InitWindow(screenWidth, screenHeight, "Big Gaming");
    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) {
        dt = GetFrameTime();

        readInput();
        update();
        render();
    }

    CloseWindow();
}
