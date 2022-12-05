//
// Created by 18017 on 11/8/2022.
//

#ifndef PROJECT_2_HEADER_H
#define PROJECT_2_HEADER_H


#include <vector>
#include "string"
using namespace std;



class Header {

private:
    vector<string>attributes;

public:
    Header() = default;

    Header(vector<string>givnAtbs){
        attributes = givnAtbs;
    }
    ~Header() = default;

    void addToHeader(string value){
        attributes.push_back(value);

    }
    vector<string>getAttributes();








};


#endif //PROJECT_2_HEADER_H
