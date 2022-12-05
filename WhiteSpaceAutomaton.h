//
// Created by 18017 on 9/28/2022.
//

#ifndef PROJECT_1_WHITESPACEAUTOMATON_H
#define PROJECT_1_WHITESPACEAUTOMATON_H


#include "Automaton.h"

class WhiteSpaceAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    WhiteSpaceAutomaton() : Automaton(TokenType::WHITESPACE) {}  // Call the base constructor

    void S0(const std::string& input) override;
};


#endif //PROJECT_1_WHITESPACEAUTOMATON_H
