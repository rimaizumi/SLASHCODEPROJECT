#include "GameLevel.h"

SettingsButton::SettingsButton() {
    settingsButton = { 20, 20, 40, 40 };
    isSettingsOpen = false;

    backcolor = {backcolor.x + 63, backcolor.y +  15, 230, 200};
    journeyButton = { settingsButton.x + 50, settingsButton.y + 10, 210, 55 };
    rankingButton = { journeyButton.x +0, journeyButton.y + 100, 210, 55 };
}

void SettingsButton::Update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

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


    DrawRectangleRec(settingsButton, isSettingsOpen ? RED : BLACK);
    DrawText("-", settingsButton.x + 15, settingsButton.y + 4, 20, WHITE);
    DrawText("-", settingsButton.x + 15, settingsButton.y + 10, 20, WHITE);
    DrawText("-", settingsButton.x + 15, settingsButton.y + 17, 20, WHITE);

    if (isSettingsOpen) {
        DrawRectangleRec(backcolor, Fade(WHITE, 0.5f)); 
        DrawRectangleRec(journeyButton, BLACK); 
        DrawText("Journey", journeyButton.x + 10, journeyButton.y + 10, 44, WHITE);

        DrawRectangleRec(rankingButton, BLACK); 
        DrawText("Ranking", rankingButton.x + 10, rankingButton.y + 10, 44, WHITE);
    }

   
}
