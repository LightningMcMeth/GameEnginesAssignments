#pragma once
#include <raylib.h>

class Player {
private:
    Vector2 position;
    float speed;
    const int size = 50;

public:
    Player();

    void handleInput(float dt);
    void update(float dt);
    void draw() const;
};