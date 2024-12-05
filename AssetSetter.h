#pragma once
#include "AssetLoader.h"
#include "Player.h"

class AssetSetter {
public:
    void loadAndSetPlayerTexture(Player& player, AssetLoader& assetLoader);
};