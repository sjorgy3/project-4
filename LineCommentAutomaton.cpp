//
// Created by 18017 on 9/29/2022.
//

#include "LineCommentAutomaton.h"

void LineCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}


void LineCommentAutomaton::S1(const std::string& input){
    if(index == (int)input.size()){
        return;
    }
    else if (input[index] == '|'){
        Serr();
    }
    else if (input[index] != '\n'){
        index++;
        inputRead++;
        S2(input);
    }

    else{
        S2(input);
    }


}
void LineCommentAutomaton::S2(const std::string& input){
    if (input[index] != '\n'){
        index++;
        inputRead++;
        S2(input);
    }
}