//
// Created by 18017 on 11/5/2022.
//

#ifndef PROJECT_2_DATABASE_H
#define PROJECT_2_DATABASE_H
#include "map"
#include "string"
#include "DatalogProgram.h"
#include "Relation.h"
#include<map>

class Database {
private:
    map<string,Relation> relations;

public:
    Database() = default;
    ~Database() = default;
    void addRelation(Relation newRelation);
    Relation* getRelation2(string relationName);
    Relation getRelationCopy(string relationName);




};


#endif //PROJECT_2_DATABASE_H
