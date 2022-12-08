//
// Created by 18017 on 10/21/2022.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H
#include <string>
#include "Parameter.h"
#include "Relation.h"
#include <vector>
#include <sstream>

using namespace std;


class Predicate {
    vector<Parameter> parameters;
    string nameToSet;
public:
    Predicate()=default;
    void addName(string nametoadd);
    void addParameter(Parameter param);
    string toString();
    string getName(){
        return nameToSet;
    }
    vector<Parameter> getParams(){
       return parameters;
    }

    void clear();


};


#endif //PROJECT_2_PREDICATE_H
