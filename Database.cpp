//
// Created by 18017 on 11/5/2022.
//

#include "Database.h"

Relation Database::getRelationCopy(string relationName) {
    return relations.at(relationName);
}

void Database::addRelation(Relation newRelation) {
    relations.insert(pair<string,Relation>(newRelation.getName(),newRelation));


}

Relation *Database::getRelation2(string relationName) {
    return &relations.at(relationName);
}
