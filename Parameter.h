//
// Created by 18017 on 10/21/2022.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Parameter {
private:
    string parameter;


public:
    Parameter() = default;
    Parameter(string name);

    string toString();
    bool isConstant();



};


#endif //PROJECT_2_PARAMETER_H
