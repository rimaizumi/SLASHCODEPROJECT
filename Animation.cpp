#include "Animation.h"

AnimatedSprite::AnimatedSprite(const char* filename, int spriteWidth, int spriteHeight, int frames, float animationSpeed)
{
    spriteSheet = LoadTexture(filename);
    sourceRect = { 0.0f, 0.0f, (float)spriteWidth, (float)spriteHeight };
    position = { 0.0f, 0.0f };
    frameTime = animationSpeed;
    frameCount = frames;
    currentFrame = 0;
}


void AnimatedSprite::Update(float deltaTime)
{
    frameTime -= deltaTime;
    if(frameTime <= 0.0f)
    {
        frameTime = 0.2f;
        currentFrame++;

        if(currentFrame >= frameCount)
            currentFrame = 0;

        sourceRect.x = (float)(currentFrame * sourceRect.width);
    }
}
void AnimatedSprite::UpdatePro(float deltaTime , int limitofFrames)
{
    frameLimit = limitofFrames;
    frameTime -= deltaTime;
    if(frameTime <= 0.0f)
    {
        frameTime = 0.2f;
        currentFrame++;
        
        if(currentFrame >= frameCount)
            currentFrame = frameLimit;

        sourceRect.x = (float)(currentFrame * sourceRect.width);
    }
}
void AnimatedSprite::Draw()
{
    DrawTextureRec(spriteSheet, sourceRect, position, WHITE);
}