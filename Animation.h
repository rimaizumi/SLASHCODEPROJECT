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
    //void update is for looped animation
    void Update(float deltaTime);
    //void updatepro is for controlled animation
    void UpdatePro(float deltaTime, int limitofFrames);
    void Draw();
};
