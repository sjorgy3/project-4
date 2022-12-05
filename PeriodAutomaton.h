//
// Created by 18017 on 9/21/2022.
//

#ifndef PROJECT_1_PERIODAUTOMATON_H
#define PROJECT_1_PERIODAUTOMATON_H



#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input)override;
};


#endif //PROJECT_1_PERIODAUTOMATON_H
