#pragma once
#include <raylib.h>
#include "Player.h"

class GameLogic {
private:
    const int screenWidth = 800;
    const int screenHeight = 600;
    int targetFPS = 60;
    float dt = 0.0f;
    Player player;

    void readInput();
    void update();
    void render();

public:
    void run();
};