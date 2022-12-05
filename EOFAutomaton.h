//
// Created by 18017 on 9/21/2022.
//

#ifndef PROJECT_1_EOFAUTOMATON_H
#define PROJECT_1_EOFAUTOMATON_H



#include "Automaton.h"

class EOFAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    EOFAutomaton() : Automaton(TokenType::ENDOFFILE) {}  // Call the base constructor

    void S0(const std::string& input)override;
};


#endif //PROJECT_1_EOFAUTOMATON_H
