#include "raylib.h"
#include "Animation.h"
#include <iostream>
using namespace std;

typedef enum GAMESCREEN {Logo = 0, Title, Menu, Gameplay,Game_language, Ending} GAMESCREEN;
int main()
{
    // Initialization
    const int screenWidth = 1440;
    const int screenHeight = 1024;


    InitWindow(screenWidth, screenHeight, "Project: Slash Code (ALPHA)");
    SetTargetFPS(60);
    GAMESCREEN currentScreen = Logo;
    int framesCounter = 0;
    // Create an instance of AnimatedSprite
    AnimatedSprite mySprite("resources/bg/Main.png", 1440, 1024, 15, 0.2f);

    SetTargetFPS(60);


    // Main game loop
    while (!WindowShouldClose())
    {
        
        switch(currentScreen)
        {
            case Logo:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = Title;
                }
            } break;
            case Title:
            {
                // TODO: Update TITLE screen variables here!
                
                float deltaTime = GetFrameTime();
                mySprite.UpdatePro(deltaTime, 13);
                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = Gameplay;
                }
            } break;
            case Gameplay:
            {
                // TODO: Update GAMEPLAY screen variables here!


                // Press enter to change to ENDING screen
                Rectangle collision_position = { 344, 293, 764, 219 };
                
                if (CheckCollisionPointRec(GetMousePosition(), collision_position)) {
                    

                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        
                        currentScreen = Game_language;
                    }
                } 
               
            } break;

             case Game_language:
            {
                // TODO: Update GAME_language screen variables here!


                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = Ending;
                }
            } break;


          

            case Ending:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = Title;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case Logo:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

                } break;
                case Title:
                {
                    // TODO: Draw TITLE screen here!
                    mySprite.Draw();
                    

                } break;
                case Gameplay:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    //background
                    DrawRectangle(0, 0, screenWidth, screenHeight,GRAY);
                    Color transparentBlack = Fade(BLACK, 0.8f);
                    Rectangle roundedRect = { (screenWidth - 1002) / 2, (screenHeight - 983) / 2, 1002, 983 };
                    DrawRectangleRounded(roundedRect, 0.1, 10, transparentBlack);
                    
                    DrawText("SLASHCODE", 509, 40, 70, WHITE);
                    DrawRectangle(300,120, 850 , 3 , WHITE);
                    DrawText("SELECT LEVEL", 559, 157, 40, WHITE);

                    //button
                    Rectangle buttonRect1 = { 344, 293, 764, 219 };
                    Color buttonColor2 = BLACK;
                    DrawRectangleRounded(buttonRect1, 0.4 , 10, buttonColor2);
                    DrawText("BEGINNER LEVEL!", 378 , 368, 76 , WHITE);

                   
                    
       
                } break;

                 case Game_language:
                {
                    // TODO: Draw GAMEPLAY screen here!
                     DrawRectangle(0, 0, screenWidth, screenHeight,GRAY);
                    Color transparentBlack = Fade(BLACK, 0.8f);
                    Rectangle roundedRect = { (screenWidth - 980) / 2, (screenHeight - 700) / 2, 980, 700 };
                    DrawRectangleRounded(roundedRect, 0.1, 10, transparentBlack);
                    
                    

                    //button
                    Rectangle buttonRect1 = { 344, 293, 764, 219 };
                    Color buttonColor2 = BLACK;
                    DrawRectangleRounded(buttonRect1, 0.4 , 10, buttonColor2);
                    DrawText("BEGINNER LEVEL!", 378 , 368, 76 , WHITE);

            

                } break;
                case Ending:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }
        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(mySprite.spriteSheet);  // Unload texture
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
