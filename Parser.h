//
// Created by 18017 on 10/10/2022.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "Lexer.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include <set>

using namespace std;

class Parser {

private:

    unsigned int tokenLocation =0;
    vector<Token*>tokens;
    DatalogProgram object;
    set<string>domain;
    Predicate newPredicate;
    Rule newRule;
    //vector<Token*>commentFreeTokens;

public:

    Parser(vector<Token *> tokensFromMain);
    ~Parser();
    DatalogProgram datalogprogram();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void scheme();
    void fact();
    void rule();
    void query();
    void headPredicate();
    void predicate();
    void predicateList();
    void parameterList();
    void stringList();
    void idList();
    void parameter();

    void match(TokenType tokenType);
};


#endif //PROJECT_1_PARSER_H
