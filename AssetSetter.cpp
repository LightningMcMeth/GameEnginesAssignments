#include "AssetSetter.h"
#include <iostream>

void AssetSetter::loadAndSetPlayerTexture(Player& player, AssetLoader& assetLoader) {
    Texture2D playerTexture = assetLoader.loadTexture("assets/player.png");
    if (playerTexture.id != 0) 
    {
        player.setTexture(playerTexture);
    }
    else 
    {
        std::cout << "My guy your textures are missing";
    }
}