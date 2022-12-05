//
// Created by 18017 on 11/5/2022.
//

#ifndef PROJECT_2_INTERPRETER_H
#define PROJECT_2_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"


class Interpreter {
private:
    DatalogProgram program;
    Database database;
public:
    Interpreter(DatalogProgram program){
        this->program = program;

    }
    Database database1();
    void interpret();
    void intepretSchemes();
    void interpretFacts();
    void interpretRules();
    void interpretQueries();


};


#endif //PROJECT_2_INTERPRETER_H
