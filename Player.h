#pragma once
#include <raylib.h>

class Player {
private:
    Vector2 position;
    float speed;
    const int size = 50;
    float rotation = 0.0f;

public:
    Player();

    void handleInput(float dt);
    void update(float dt);
    void draw() const;

    Vector2 getPosition() const { return position; }
    int getSize() const { return size; }
    void setPositionX(float x) { position.x = x; }
    void setPositionY(float y) { position.y = y; }
};