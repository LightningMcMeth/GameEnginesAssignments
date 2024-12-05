#include "AssetLoader.h"

Texture2D AssetLoader::loadTexture(const std::string& filePath) {
    return LoadTexture(filePath.c_str());
}

void AssetLoader::unloadTexture(Texture2D texture) {
    UnloadTexture(texture);
}