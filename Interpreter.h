//
// Created by 18017 on 11/5/2022.
//

#ifndef PROJECT_2_INTERPRETER_H
#define PROJECT_2_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include <fstream>

class Interpreter {
private:
    DatalogProgram program;
    Database database;
    bool isDone;


public:

    Interpreter(const DatalogProgram &program){
        this->program = program;

    }
    Database database1();

    void intepretSchemes();
    void interpretFacts();
    void interpretRules();
    void interpretQueries();

    Relation interpretPredicate(Predicate predicate);
    vector<unsigned int> projectInd(Rule currRule, Header targRule);


};


#endif //PROJECT_2_INTERPRETER_H
