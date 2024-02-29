#include "raylib.h"

class AnimatedSprite {
public:
    Texture2D spriteSheet;
    Rectangle sourceRect;
    Vector2 position;
    float frameTime;
    int frameCount;
    int currentFrame;
    int frameLimit;

    AnimatedSprite(const char* filename, int spriteWidth, int spriteHeight, int frames, float animationSpeed);

    void Update(float deltaTime);
    void UpdatePro(float deltaTime, int limitofFrames);
    void Draw();
};