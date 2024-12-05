#include "GameSaver.h"
#include <iostream>
#include <filesystem>

void GameSaver::saveGameState(const Player& player) {
    std::filesystem::create_directories("save");

    std::ofstream outFile("save/game_state.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Could not open save file for writing!" << std::endl;
        return;
    }

    Vector2 position = player.getPosition();
    float rotation = player.getRotation();

    outFile.write(reinterpret_cast<const char*>(&position), sizeof(position));
    outFile.write(reinterpret_cast<const char*>(&rotation), sizeof(rotation));

    outFile.close();
    std::cout << "Game state saved successfully!" << std::endl;
}

void GameSaver::loadGameState(Player& player) {
    std::ifstream inFile("save/game_state.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: Could not open save file for reading!" << std::endl;
        return;
    }

    Vector2 position;
    float rotation;

    inFile.read(reinterpret_cast<char*>(&position), sizeof(position));
    inFile.read(reinterpret_cast<char*>(&rotation), sizeof(rotation));

    player.setPosition(position);
    player.setRotation(rotation);

    inFile.close();
    std::cout << "Game state loaded successfully!" << std::endl;
}
