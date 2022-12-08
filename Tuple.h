//
// Created by 18017 on 11/8/2022.
//

#ifndef PROJECT_2_TUPLE_H
#define PROJECT_2_TUPLE_H

#include <string>
#include <vector>
#include <set>

typedef unsigned int Index;
typedef unsigned int Count;

using namespace std;

class Tuple {
private:
    vector<string>values;

public:
    Tuple() = default;
    ~Tuple()= default;

    void addValue(string value) {
        values.push_back(value);
    }

    string getValue(unsigned int i){
        return values.at(i);
    }
    vector<string>getValues();





    bool operator < (const Tuple &rhs) const{
    return values < rhs.values;


}

};


#endif //PROJECT_2_TUPLE_H
