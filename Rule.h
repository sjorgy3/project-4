//
// Created by 18017 on 10/21/2022.
//

#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H
#include "Predicate.h"
#include <string>
#include <vector>
#include <sstream>

class Rule {
    vector<Predicate> predicates;
    Predicate headPredicate;


public:

    Rule()=default;
    void addHeadPredicate(Predicate pred);
    void addBodyPredicate(Predicate pred);
    string toString();

};


#endif //PROJECT_2_RULE_H
