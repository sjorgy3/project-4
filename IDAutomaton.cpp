//
// Created by 18017 on 9/21/2022.
//

#include "IDAutomaton.h"
void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) {
        inputRead = 1;
        index++;
        S1(input);

    }
    else {
        Serr();
    }
}
void IDAutomaton::S1(const std::string &input) {
    if (std::isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);

    }
}