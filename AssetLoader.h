#pragma once

#include <raylib.h>
#include <string>

class AssetLoader {
public:
    Texture2D loadTexture(const std::string& filePath);

    void unloadTexture(Texture2D texture);
};