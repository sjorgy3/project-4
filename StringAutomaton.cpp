//
// Created by 18017 on 9/21/2022.
//

#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {

    if(index> input.size()-1){
        inputRead=0;
    }
    else if(input[index] == '\n'){
        newLines++;
        inputRead++;
        index++;

        S1(input);


    }
    else if (input[index] == '\'' && input[index+1] == '\'') {
        inputRead++;
        inputRead++;
        index++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'' && input[index+1] != '\'') {
        inputRead++;
        index++;

    }
    else if (input[index] != '\'' || input[index] != '\n') {
        inputRead++;
        index++;
        S1(input);
    }

    else {
        Serr();
    }
}