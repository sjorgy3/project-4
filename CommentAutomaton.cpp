//
// Created by 18017 on 9/21/2022.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    } else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if(index > (int)input.size()-1){
        inputRead=0;
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);

    }
    else {
        Serr();
    }
}
void CommentAutomaton::S2(const std::string& input){
    if(index> (int)input.size()-1){
        inputRead=0;
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
        if (input[index] == '\n'){
            newLines++;
        }
        S2(input);
    }
    else if (input[index] == '|'){
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void CommentAutomaton::S3(const std::string& input){
    if(index> (int)input.size()-1){
        inputRead=0;
    }
    else if (input[index] == '|'){
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] != '#'){
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '#'){
        inputRead++;
        index++;
    }
    else{
        Serr();
    }


}