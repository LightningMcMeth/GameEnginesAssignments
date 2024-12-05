#pragma once

#include "Player.h"
#include <fstream>

class GameSaver {
public:
    void saveGameState(const Player& player);
    void loadGameState(Player& player);
};