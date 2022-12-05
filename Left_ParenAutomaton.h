//
// Created by 18017 on 9/21/2022.
//

#ifndef PROJECT_1_LEFT_PARENAUTOMATON_H
#define PROJECT_1_LEFT_PARENAUTOMATON_H



#include "Automaton.h"

class Left_ParenAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    Left_ParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input)override;
};


#endif //PROJECT_1_LEFT_PARENAUTOMATON_H
