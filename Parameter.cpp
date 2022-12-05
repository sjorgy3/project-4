//
// Created by 18017 on 10/21/2022.
//

#include "Parameter.h"

string Parameter::toString() {

    return parameter;
}

Parameter::Parameter(string s) {
    parameter=s;

}

bool Parameter::isConstant() {
    if (parameter.at(0) == '\''){
        return true;

    }
    return false;
}
