//
// Created by 18017 on 9/21/2022.
//
using namespace std;
#include "UndefinedAutomaton.h"
void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead = 1;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}


void UndefinedAutomaton::S1(const std::string& input) {
     if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);

    }
     else if (input[index] == '\n'){
         inputRead++;
         index++;
         newLines++;
         S2(input);
     }
    else {
        Serr();
    }
}
void UndefinedAutomaton::S2(const std::string& input){
    if(index == (int)input.size()){
        return;
    }
    else if (input[index] == '\n'){
        inputRead++;
        index++;
        newLines++;
        S2(input);
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
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
void UndefinedAutomaton::S3(const std::string& input){
    if(index> (int)input.size()-1){
        return;
    }
    else if (input[index] == '\n'){
        inputRead++;
        index++;
        newLines++;
        S2(input);
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
void UndefinedAutomaton::S4(const std::string &input) {
    if (input[index] == '\'') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void UndefinedAutomaton::S5(const std::string& input) {

    if(index> (int)input.size()-1){
        return;
    }
    else if (input[index] == '\n'){
        inputRead++;
        index++;
        newLines++;
        S5(input);
    }
    else if (input[index] == '\'' && input[index+1] == '\'') {
        inputRead++;
        inputRead++;
        index++;
        index++;
        S5(input);
    }
    else if (input[index] == '\'' && input[index+1] != '\'') {
        inputRead++;
        index++;

    }
    else if (input[index] != '\'' || input[index] != '\n') {
        inputRead++;
        index++;
        S5(input);
    }

    else {
        Serr();
    }
}














/*void UndefinedAutomaton::S2(const std::string& input){
    if(index > (int)input.size()-1){
        inputRead++;
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
        S2(input);

    }
    else if(input[index] == '|') {
        S3(input);
    }
    else if(input[index] == '#') {
        S4(input);
    }
    else{
        Serr();
    }
}
void UndefinedAutomaton::S3(const std::string& input){
    if(index > (int)input.size()-1){
        inputRead++;
    }
    else if (input[index] != '#') {
        inputRead++;
        index++;
        S2(input)

    }
    else {
        Serr();
    }
}
void UndefinedAutomaton::S4(const std::string& input){
    if(index > (int)input.size()-1){
        inputRead++;
    }
    else if(input[index] == '|') {
        inputRead++;
        index++;

    }*/


    //strings that dont terminate properly
