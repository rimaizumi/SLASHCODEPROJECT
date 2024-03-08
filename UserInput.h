#include "raylib.h"
#include <iostream>
#include <string>



class UserInput{

    public:
    UserInput();
    void Input();
    std::string userInput;
    std::string displayText;
    int textWidth;
    bool type;
    Rectangle inputBox;
};