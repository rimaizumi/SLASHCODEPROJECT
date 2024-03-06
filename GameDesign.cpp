#include "GameDesign.h"

// constractor
SettingsButton::SettingsButton() {
    // initialize
    //design
    roundedRect = { (1440 - 1002) / 2, (1024 - 983) / 2, 1002, 983 };
    buttonRect1 = { 344, 293, 764, 219 };
    //setting button
    settingsButton = { 20, 20, 30, 30 };
    isSettingsOpen = false;
    

    backcolor = {backcolor.x + 10, backcolor.y +  10, 330, 270};
    journeyButton = { settingsButton.x + 50, settingsButton.y + 50, 210, 55 };
    rankingButton = { journeyButton.x +0, journeyButton.y + 110, 210, 55 };
}

void SettingsButton::Update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        // gagawing true yung issettingbutton
        if (CheckCollisionPointRec(mousePos, settingsButton)) {
            isSettingsOpen = !isSettingsOpen;
        } else if (isSettingsOpen && CheckCollisionPointRec(mousePos, journeyButton)) {
            // Handle Journey button click
            // Add your action here
        } else if (isSettingsOpen && CheckCollisionPointRec(mousePos, rankingButton)) {
            // Handle Ranking button click
            // Add your action here
        }
    }
}

void SettingsButton::Draw() {

    //design
        DrawRectangleRounded(roundedRect, 0.1, 10,  Fade(BLACK, 0.8f));
        DrawText("SLASHCODE", 509, 40, 70, WHITE);
        DrawRectangle(300,120, 850 , 3 , WHITE);
        DrawText("SELECT LEVEL", 559, 157, 40, WHITE);
        DrawRectangleRounded(buttonRect1, 0.4 , 10, BLACK);
        DrawText("BEGINNER LEVEL!", 378 , 368, 76 , WHITE);
}
void SettingsButton::DrawSetting(){
    
    // draw depending what is the value of the isSettingOpen
        DrawRectangleRec(settingsButton, isSettingsOpen ? RED: BLACK);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 1, 20, WHITE);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 6, 20, WHITE);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 11 , 20, WHITE);

    
    // if Setting is true this will run
    if (isSettingsOpen) { 
        DrawRectangleRounded(backcolor, 0.1, 10, Fade(WHITE, 0.5f));
        DrawRectangleRec(settingsButton, isSettingsOpen ? RED: BLACK);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 1, 20, WHITE);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 6, 20, WHITE);
        DrawText("-", settingsButton.x + 11, settingsButton.y + 11 , 20, WHITE);

        DrawRectangleRec(journeyButton,Fade(WHITE,0.0f)); 
        DrawText("Journey", journeyButton.x + 10, journeyButton.y + 10, 44, BLACK);

        DrawRectangle(settingsButton.x,journeyButton.y+60 , 310,2,BLACK);

        DrawRectangleRec(rankingButton, Fade(WHITE,0.0f)); 
        DrawText("Ranking", rankingButton.x + 10, rankingButton.y + 10, 44, BLACK);
        DrawRectangle(settingsButton.x,rankingButton.y+60 , 310,2,BLACK);
    }
}

void SettingsButton::Drawlanguage() {

    //design
        DrawRectangleRounded(roundedRect, 0.1, 10,  Fade(BLACK, 0.8f));
        DrawText("SLASHCODE", 509, 40, 70, WHITE);
        DrawRectangle(300,120, 850 , 3 , WHITE);
        DrawText("SELECT LANGUAGE", 520, 157, 40, WHITE);
        DrawRectangleRounded(buttonRect1, 0.4 , 10, BLACK);
        DrawText("PYTHON", 570 , 368, 76 , WHITE);
}
void SettingsButton::DrawSlashcode() {

    //design
    DrawRectangle(0, 0, 1440, 1024,WHITE);
    DrawRectangle(0, 512, 1440, 1024,DARKGRAY);
    DrawRectangle(0, 512, 1440, 40 ,BLACK);
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
    }

   

