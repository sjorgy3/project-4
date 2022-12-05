//
// Created by 18017 on 10/21/2022.
//

#include "Predicate.h"





void Predicate::addName(string nametoadd) {
    nameToSet = nametoadd;

}

void Predicate::addParameter(Parameter param) {
parameters.push_back(param);
}

string Predicate::toString() {
    stringstream ss;
    ss << nameToSet << "(";
    for(unsigned int i = 0; i < parameters.size(); i++){
        ss << parameters.at(i).toString();
        if (i != parameters.size()-1){
            ss << ",";
        }
    }
    ss << ")";



    return ss.str();
}

void Predicate::clear() {


}
