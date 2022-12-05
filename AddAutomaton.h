//
// Created by 18017 on 9/21/2022.
//

#ifndef PROJECT_1_ADDAUTOMATON_H
#define PROJECT_1_ADDAUTOMATON_H



#include "Automaton.h"

class AddAutomaton : public Automaton
{

public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input) override;
};


#endif //PROJECT_1_ADDAUTOMATON_H
