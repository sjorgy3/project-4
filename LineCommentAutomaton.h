//
// Created by 18017 on 9/29/2022.
//

#ifndef PROJECT_1_LINECOMMENTAUTOMATON_H
#define PROJECT_1_LINECOMMENTAUTOMATON_H


#include "Automaton.h"

class LineCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);

public:
    LineCommentAutomaton() : Automaton(TokenType::LINECOMMENT) {}  // Call the base constructor

    void S0(const std::string& input)override;
};


#endif //PROJECT_1_COMMENTAUTOMATON_H
