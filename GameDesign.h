
#include "raylib.h"

class SettingsButton {
public:
    // constructor
    SettingsButton();
    // functions
    void display();
    void Update();
    void Draw();
    void DrawSetting();
    void Drawlanguage();
    void DrawSlashcode();
  
    

private:
    // variables

    // design

    Rectangle roundedRect;
    Rectangle buttonRect1;

    //setting button
    Rectangle settingsButton;
    bool isSettingsOpen;
    Rectangle backcolor;
    Rectangle journeyButton;
    Rectangle rankingButton;
    Rectangle Xshape;
};
