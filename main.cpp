#include <iostream>
#include <raylib.h>
using namespace std;
Texture2D loading;
Texture2D logo;
typedef enum GAMESCREEN {Logo = 0, Title, Menu, Gameplay, Ending} GAMESCREEN;
int main () {

    //Screen Settings
    const int screenWidth = 1080;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Project: Slash Code (ALPHA)");
    SetTargetFPS(60);
    GAMESCREEN currentScreen = Logo;

    /**************************      USED FOR TITLE SCREEN ANIMATION        **************************************************/
    loading = LoadTexture("resources/bg/Main.png");
    int currentFrame = 0;
    Rectangle frameRec = { 0.0f, 0.0f, (float)loading.width/15, (float)loading.height };
    int framesCounter = 0;
    int framesSpeed = 7;

    /**************************      USED FOR LOGO SCREEN ANIMATION        **************************************************/            
    logo = LoadTexture("resources/bg/Logot.png");
    Rectangle frameRecLogo = { 0.0f, 0.0f, (float)logo.width/18, (float)logo.height };
   
   
    SetTargetFPS(60);
    while (!WindowShouldClose()) //checks if the user clicks the close button
    {   
        /********        This handles the switching of the screen           *******/
        switch(currentScreen) 
        {
            case Logo: 
            {
                
                framesCounter++;
                if(GetTime() > 5.0f) {
                    currentScreen = Title;
                }
            }break;

            case Title: 
            {

            }
        }
        
        //Draws all the important thing in the program


        BeginDrawing();
        ClearBackground(BLUE);
        switch (currentScreen)
        {
            case Logo:
            {
                if (framesCounter >= (60/framesSpeed))
                {
                    framesCounter = 0;
                    currentFrame++;

                    if (currentFrame > 14) currentFrame = 14;

                    frameRecLogo.x = (float)currentFrame*(float)logo.width/18;
                }
            }
        }
        
        /*****************************TITLE*****************************/
        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 14) currentFrame = 14;

            frameRec.x = (float)currentFrame*(float)loading.width/15;
        }
        /****************************************************************/
        
        DrawTextureRec(loading, frameRec, Vector2{0.0f, 0.0f}, WHITE); 
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}