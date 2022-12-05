//
// Created by 18017 on 10/21/2022.
//

#include "Rule.h"

void Rule::addHeadPredicate(Predicate pred) {
headPredicate = pred;

}

void Rule::addBodyPredicate(Predicate pred) {
predicates.push_back(pred);
}

string Rule::toString() {
    stringstream ss;
    ss << headPredicate.toString() << " :- ";
    for(unsigned int i = 0; i < predicates.size(); i++){
        ss << predicates.at(i).toString();
        if (i != predicates.size()-1){
            ss << ",";
        }
    }




    return ss.str();
}
