#include "raylib.h"
#include "Animation.h"
#include "GameLevel.h"
#include "Slashcode.h"
#include <iostream>
using namespace std;

typedef enum GAMESCREEN {Logo = 0, Title, Menu, Gameplay,Game_language, slashcode, Ending} GAMESCREEN;
int main()
{
    // Initialization
    const int screenWidth = 1440;
    const int screenHeight = 1024;
    string userInput = "";
    SettingsButton settingsButton;
   

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

                settingsButton.Update();
               
            } break;

             case Game_language:
            {
                // TODO: Update GAME_language screen variables here!

                Rectangle collision_position = { 344, 293, 764, 219 };
                
                if (CheckCollisionPointRec(GetMousePosition(), collision_position)) {
                    

                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        
                        currentScreen = slashcode;
                    }
                } 

                settingsButton.Update();
            } break;

            case slashcode:{

              
            }break;
          

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
                    settingsButton.Draw();
                    

                   
                    
       
                } break;

                 case Game_language:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight,GRAY);
                    Color transparentBlack = Fade(BLACK, 0.8f);
                    Rectangle roundedRect = { (screenWidth - 1002) / 2, (screenHeight - 983) / 2, 1002, 983 };
                    DrawRectangleRounded(roundedRect, 0.1, 10, transparentBlack);
                    
                    DrawText("SLASHCODE", 509, 40, 70, WHITE);
                    DrawRectangle(300,120, 850 , 3 , WHITE);
                    DrawText("SELECT LANGUAGE", 520, 157, 40, WHITE);

                    //button
                    Rectangle buttonRect1 = { 344, 293, 764, 219 };
                    Color buttonColor2 = BLACK;
                    DrawRectangleRounded(buttonRect1, 0.4 , 10, buttonColor2);
                    DrawText("PYTHON", 570 , 368, 76 , WHITE);
                    settingsButton.Draw();
                    

                } break;

                case slashcode:{
                    DrawRectangle(0, 0, screenWidth, screenHeight,WHITE);
                    DrawRectangle(0, 512, screenWidth, screenHeight,DARKGRAY);
                    DrawRectangle(0, 512, screenWidth, 40 ,BLACK);
                    DrawRectangle(400, 512, 5,512,BLACK );
                    DrawRectangle(1040, 512, 5,512,BLACK );
                    DrawRectangle(0,512,190,38,DARKGRAY);
                    DrawRectangle(405,512,190,38,DARKGRAY);
                    DrawRectangle(1050,512,190,38,DARKGRAY);
                    DrawText("ACTIVITY",10 , 518, 30, WHITE);
                    DrawText("Main.py",430 , 518, 30, WHITE);
                    DrawText("OUTPUT",1070 , 518, 30, WHITE);
                    DrawText("In Python, the print function is used to output ", 10, 565, 16, WHITE);
                    DrawText("information to the console or terminal. It allows ", 10, 590, 16, WHITE);   
                    DrawText("you to display text, variables, or expressions. ", 10, 610, 16, WHITE); 
                    DrawText("The basic syntax of the print function is:", 10, 635, 16, WHITE); 
                    DrawRectangle(5, 675, 380, 40,WHITE ); 
                    DrawText("print(\"This is an example of printing a text.\")", 10, 685, 16, BLACK); 
                    DrawRectangle(5, 775, 380, 100,WHITE );
                    DrawText("INSTRUCTION:", 10, 790, 16, BLACK);  
                    DrawText("print(\"Hello World!\")", 10, 830, 16, BLACK);               


                }break;
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
