//
// Created by 18017 on 10/10/2022.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H


#include <vector>
#include "Predicate.h"
#include "Rule.h"
#include "set"

using namespace std;

class DatalogProgram {
    vector<Predicate>schemes;
    vector<Predicate>facts;
    vector<Rule>rules;
    vector<Predicate>queries;
    set<string>domain;


public:
    void addToSchemes(Predicate newScheme);
    void addToFacts(Predicate newFact);
    void addToRules(Rule newRule);
    void addToQueries(Predicate newQuery);
    void addToDomain(Parameter newParameter);
    void toString();

    vector<Predicate> getSchemes();


    vector<Predicate> getFacts();

    vector<Predicate> getQueries();
};


#endif //PROJECT_2_DATALOGPROGRAM_H
