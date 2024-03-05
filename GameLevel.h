
#include "raylib.h"

class SettingsButton {
public:
    SettingsButton();
    void display();
    void Update();
    void Draw();

private:
    Rectangle settingsButton;
    bool isSettingsOpen;


    
    Rectangle backcolor;
    Rectangle journeyButton;
    Rectangle rankingButton;
};
