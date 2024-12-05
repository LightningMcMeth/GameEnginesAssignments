#pragma once
#include <raylib.h>

class Player {
private:
    Vector2 position;
    float speed;
    const int size = 50;
    float rotation = 0.0f;
    Texture2D playerTexture;

public:
    Player();
    ~Player();

    void handleInput(float dt);
    void update(float dt);
    void draw() const;
    void drawPlayerTexture() const;
    void drawPlayerPrimitive() const;
    void setTexture(Texture2D newTexture);

    Vector2 getPosition() const { return position; }
    int getSize() const { return size; }
    float getRotation() const { return rotation; }

    void setPosition(Vector2 newPos) { position = newPos; }
    void setPositionX(float x) { position.x = x; }
    void setPositionY(float y) { position.y = y; }
    void setRotation(float newRotation) { rotation = newRotation; }
};