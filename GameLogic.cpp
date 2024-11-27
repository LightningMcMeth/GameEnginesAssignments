#include "GameLogic.h"

void GameLogic::readInput() {
    if (IsKeyPressed(KEY_Q)) {
        CloseWindow();
    }

    player.handleInput(dt);
}

void GameLogic::update() {
    player.update(dt);
}

void GameLogic::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    player.draw();

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
