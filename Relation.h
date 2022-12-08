//
// Created by 18017 on 11/5/2022.
//

#ifndef PROJECT_2_RELATION_H
#define PROJECT_2_RELATION_H
#include "string"
#include "Header.h"
#include "Relation.h"
#include "Tuple.h"
#include "set"
#include "list"
#include "sstream"
using namespace std;



class Relation {
private:
    string name;
    Header givenHeader;
    set<Tuple> rows;
public:
    Relation() = default;

    Relation(string newName, Header newHeader) {
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

    Relation select(int index, const string& value);

    Relation select2(int index1, int index2);

    Relation project(const vector<int>& indices);

    Relation rename(const vector<string>& attributes);

    void toString();

    int numTuples();



    Relation naturalJoin(Relation relationToJoin);

    bool unionRelation(Relation relationFromRuleEval);

    bool isJoinable(Tuple tuple, Tuple tuple1, const vector<pair<int, int>>& vector);

    void setRows(Tuple tuple);

};


#endif //PROJECT_2_RELATION_H
