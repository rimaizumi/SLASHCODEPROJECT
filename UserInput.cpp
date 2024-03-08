#include "UserInput.h"
#include "Activities.h"

UserInput::UserInput(){
    type = false;
    userInput = "";
    inputBox  = {420, 560, 90, 40};
    
    
}



void UserInput::Input() {
    // make the shift not toggle
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
        type = true;
    } else {
        type = false;
    }

    std::string displayText = (type ? "[Caps]" : "[Lower]") + userInput;

    int key = GetKeyPressed();
    while (key > 0) {
        // Check if the key is a letter, number, or symbol and modify the input accordingly
        if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || 
             (key >= '0' && key <= '9')) && (userInput.size() < 255)) {
            if (type) {
                // Convert to uppercase if the flag is set
                userInput += (char)toupper(key);
            } else {
                // Convert to lowercase if the flag is not set
                userInput += (char)tolower(key);
            }
        } else if (key >= 32 && key <= 126) {
            // Include symbols if they are printable characters
            userInput += (char)key;
        }

        key = GetKeyPressed();
    }

    // Handle backspace
    if (IsKeyPressed(KEY_BACKSPACE) && !userInput.empty()) {
        userInput.pop_back();
    }

    int textWidth = MeasureText(displayText.c_str(), 20);
    while (textWidth > inputBox.width + 50) { // Assuming the white box has a width of 200
        userInput.pop_back();
        displayText = (type ? "[Caps]" : "[Lower]") + userInput;
        textWidth = MeasureText(displayText.c_str(), 20);
    }
    
}
