#pragma once
#include <raylib.h>
#include "Player.h"
#include "AssetLoader.h"
#include "AssetSetter.h"
#include "GameSaver.h"

class GameLogic {
private:
    const int screenWidth = 800;
    const int screenHeight = 600;
    int targetFPS = 60;
    float dt = 0.0f;
    bool isPaused = false;
    Player player;
    AssetLoader assetLoader;
    AssetSetter assetSetter;
    GameSaver gameSaver;

    void readInput();
    void update();
    void render();

    void initialize();
    void checkPlayerCollisionWithBorder();

public:
    void run();
};