//
// Created by 18017 on 10/10/2022.
//

#include <iostream>
#include "DatalogProgram.h"
#include "Predicate.h"
void DatalogProgram::addToSchemes(Predicate newScheme) {
    schemes.push_back(newScheme);

}

void DatalogProgram::addToFacts(Predicate newFact) {
    facts.push_back(newFact);
}

void DatalogProgram::addToRules(Rule newRule) {
    rules.push_back(newRule);

}

void DatalogProgram::addToQueries(Predicate newQuery) {
    queries.push_back(newQuery);
}

void DatalogProgram::toString() {
    /*cout << "Success!" << endl;
    cout << "Schemes(" << schemes.size() << "):" << endl;*/
    for (unsigned int i = 0; i < schemes.size(); i++){
       /* cout << "  " << schemes.at(i).toString() << endl;*/
    }
    /*cout << "Facts(" << facts.size() << "):" << endl;*/
    for (unsigned int i = 0; i < facts.size(); i++) {
        /*cout << "  " << facts.at(i).toString() << "." << endl;*/
    }
    /*cout << "Rules(" << rules.size() << "):" << endl;*/
    for (unsigned int i = 0; i < rules.size(); i++){
        //cout << "  " << rules.at(i).toString() << "." << endl;
    }
    /*cout << "Queries(" << queries.size() << "):" << endl;*/
    for (unsigned int i = 0; i < queries.size(); i++){
        //cout << "  " << queries.at(i).toString() << "?"<< endl;
    }
    /*cout << "Domain(" << domain.size() << "):" << endl;*/
    for (auto it=domain.begin(); it != domain.end(); ++it){

    }
       /* cout << "  " << *it << endl;*/





}

void DatalogProgram::addToDomain(Parameter newParameter) {
    domain.insert(newParameter.toString());
}

vector<Predicate> DatalogProgram::getSchemes() {
    return schemes;
}
vector<Predicate> DatalogProgram::getFacts() {
    return facts;
}
vector<Predicate> DatalogProgram::getQueries() {
    return queries;
}

