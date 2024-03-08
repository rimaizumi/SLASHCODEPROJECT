    #include "Activities.h"
    #include "UserInput.h"


    UserInput user_input;

    Activity::Activity(){
        //activity 1 print
        inputBox  = {420, 560, 80, 40};
        inputBox1 = {540,560, 130, 40};

        strAnswer = "print"; 
        RunButton = {980,516,30,30};
        showButton = false;
        
        vertex1 = {980 + 30, 530};         // Top-right vertex
        vertex2 = {980, 530 - 15};         // Bottom vertex
        vertex3 = {980, 530 + 15};
        inputBoxSelected = false;
        inputBoxSelected1 = false;
    }
    //----------------------------------------------------------------------------------

    void Activity::CheckAnswer() {
    QuestionState currQuestion = question1;

    switch(currQuestion)
    {
        case question1:
        {
            user_input.Input(); 

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                // Check if the mouse click is inside the inputBox
                if (CheckCollisionPointRec(mousePos, inputBox )) {
                    inputBoxSelected = true;
                     // Set the flag to enable text input
                } if(CheckCollisionPointRec(mousePos, inputBox1 )){
                    inputBoxSelected1 = true;
               
                }
                else {
                    inputBoxSelected = false;
                     // Reset the flag if clicked outside the inputBox
                }
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            // gagawing true yung issettingbutton
            if (CheckCollisionPointRec(mousePos, RunButton)) {
                showButton = !showButton;
                
            } /*else if (isSettingsOpen && CheckCollisionPointRec(mousePos, journeyButton)) {
                // Handle Journey button click
                temporaryUnavailable = !temporaryUnavailable;
                
            } else if (isSettingsOpen && CheckCollisionPointRec(mousePos, rankingButton)) {
                // Handle Ranking button click
                temporaryUnavailable = !temporaryUnavailable;
            }
            else if (temporaryUnavailable && CheckCollisionPointRec(mousePos, Xshape1_Collision)) {
                temporaryUnavailable = !temporaryUnavailable;
            }*/
            
        }
        
    }break;

        case question2:
            {
            user_input.Input();
            if(IsKeyDown(KEY_F10)){

                if (user_input.userInput == strAnswer) {
                    // Correct answer
                    DrawText("Correct2!", 600, 200, 30, GREEN);
                    currQuestion = question3;
                } else {
                    // Incorrect answer
                DrawText("Incorrect!", 600, 650, 30, RED);
                }
            }   
        }break;

        case question3:
            {
            user_input.Input();
            if(IsKeyDown(KEY_F10)){

                if (user_input.userInput == strAnswer) {
                    // Correct answer
                    DrawText("Correct3!", 600, 200, 30, GREEN);
                    currQuestion = question4;
                } else {
                    // Incorrect answer
                DrawText("Incorrect!", 600, 650, 30, RED);
                }
            }   
        }break;

        case question4:
            {
            user_input.Input();
            if(IsKeyDown(KEY_F10)){

                if (user_input.userInput == strAnswer) {
                    // Correct answer
                    DrawText("Correct4!", 600, 200, 30, GREEN);
                    currQuestion = question1;
                } else {
                    // Incorrect answer
                DrawText("Incorrect!", 600, 650, 30, RED);
                }
            }   
        }break;

    default:
    break;
    }
}
        



    //-------------------------------------end of switch-------------------------------------------------








void Activity::DrawInputBox(){
    
    DrawTriangle(vertex1, vertex2, vertex3, GREEN);
    DrawRectangleRec(RunButton,Fade(WHITE, 0.0f ));
    QuestionState currQuestion = question1;
    switch (currQuestion)
    {

        case question1:{
            
            DrawRectangleRounded(inputBox, 0.1 , 10 , WHITE);
            DrawRectangleRounded(inputBox1, 0.1 , 10 , WHITE);


              if (inputBoxSelected) {
                DrawRectangle(inputBox.x + 5 + MeasureText(user_input.displayText.c_str(), 20), inputBox.y + 5, 2, 30, BLACK);
                DrawText(user_input.userInput.c_str(), inputBox.x + 5, inputBox.y + 5, 20, BLACK);
                if(!inputBoxSelected){
                     DrawRectangle(inputBox.x + 5 + MeasureText(user_input.displayText.c_str(), 20), inputBox.y + 5, 2, 30, BLACK);
                    DrawText(user_input.userInput.c_str(), inputBox.x + 5, inputBox.y + 5, 20, BLACK);
                }

            }if (inputBoxSelected1) {
                DrawRectangle(inputBox1.x + 5 + MeasureText(user_input.displayText.c_str(), 20), inputBox1.y + 5, 2, 30, BLACK);
                DrawText(user_input.userInput.c_str(), inputBox1.x + 5, inputBox1.y + 5, 20, BLACK);
                if(!inputBoxSelected1){
                     DrawRectangle(inputBox1.x + 5 + MeasureText(user_input.displayText.c_str(), 20), inputBox1.y + 5, 2, 30, BLACK);
                    DrawText(user_input.userInput.c_str(), inputBox1.x + 5, inputBox1.y + 5, 20, BLACK);
                }

            } else {
                // DrawText(user_input.userInput.c_str(), ...); // Draw the input without any rectangle if none is selected
            }
        
            if(showButton){

                if (user_input.userInput == strAnswer ){
                    DrawText("Correct!", 1100, 600, 30, GREEN);
                } else if (user_input.userInput != strAnswer && showButton){
                DrawText("Incorrect!", 1100, 650, 30, RED);
                }
            }   

        }break;

        case question2:{
            DrawText(user_input.userInput.c_str(), inputBox.x + 5, inputBox.y + 5, 20, BLACK);
            DrawText(user_input.userInput.c_str(), inputBox.x + 5, inputBox.y + 5, 20, BLACK);
            DrawText("Correct2!", 600, 200, 30, GREEN);

        }break;


    default:
    break;
    }   
                
}








