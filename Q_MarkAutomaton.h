//
// Created by 18017 on 9/21/2022.
//

#ifndef PROJECT_1_Q_MARKAUTOMATON_H
#define PROJECT_1_Q_MARKAUTOMATON_H



#include "Automaton.h"

class Q_MarkAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input)override;
};


#endif //PROJECT_1_Q_MARKAUTOMATON_H
