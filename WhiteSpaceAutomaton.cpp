//
// Created by 18017 on 9/28/2022.
//

#include "WhiteSpaceAutomaton.h"
void WhiteSpaceAutomaton::S0(const std::string& input) {

    if (input[index] == ' '|| input[index] == '\t') {
        inputRead = 1;
    }
    else if (input[index] == '\n') {
        inputRead = 1;
        newLines++;
    }

    else {
        Serr();
    }
}