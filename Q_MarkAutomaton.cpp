//
// Created by 18017 on 9/21/2022.
//

#include "Q_MarkAutomaton.h"
void Q_MarkAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}