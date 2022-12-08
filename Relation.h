//
// Created by 18017 on 11/5/2022.
//

#ifndef PROJECT_2_RELATION_H
#define PROJECT_2_RELATION_H
#include <string>
#include "Header.h"
#include "Tuple.h"
#include <set>
#include <list>
#include <sstream>
using namespace std;

class Relation {
private:
    string name;
    Header givenHeader;
    set<Tuple> rows;
public:
    Relation() = default;

    Relation(const string &newName, const Header& newHeader) {
        this->name = newName;
        this->givenHeader = newHeader;
    }

    string getName() {
        return name;
    }


    void setHeader(const Header& header);
    Header getHeader();

    void addTuple(const Tuple& newTup);
    set<Tuple> getRows();

    Relation select(unsigned int index, const string& value);

    Relation select2(unsigned int index1, unsigned int index2);

    Relation project(const vector<unsigned int>& indices);

    Relation rename(const vector<string>& attributes);

    void toString();

    unsigned int numTuples();



    Relation naturalJoin(Relation relationToJoin);

    bool unionRelation(Relation relationFromRuleEval);

    bool isJoinable(Tuple tuple, Tuple tuple1, const vector<pair<unsigned int, unsigned int>>& vector);

};


#endif //PROJECT_2_RELATION_H
