#include "raylib.h"
#include <iostream>
#include <string>

class Activity{
    public:
    typedef enum QuestionState { question1 = 0, question2, question3, question4 } QuestionState;
        Activity();
        void Input();
        void DrawInputBox();
        void CheckAnswer();
       

    private:
        Rectangle inputBox;
        Rectangle inputBox1;
        std::string strAnswer;
        Rectangle RunButton;
        Vector2 vertex1;
        Vector2 vertex2; 
        Vector2 vertex3; 
        bool showButton; 
        bool inputBoxSelected;
        bool inputBoxSelected1;
};