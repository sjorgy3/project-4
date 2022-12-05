//
// Created by 18017 on 11/5/2022.
//

#include <iostream>
#include "Relation.h"
#include "string"

Relation Relation::select(int index, string value) {
    Relation relationToReturn;
    relationToReturn.setHeader(this->givenHeader);
    for (auto row: this->rows){
        if(row.getValue(index) == value){
            relationToReturn.addTuple(row);
        }
    }


    return relationToReturn;
}
Relation Relation::select2(int index1, int index2) {
    Relation relationToReturn;
    relationToReturn.setHeader(this->givenHeader);

    for (auto row:this->rows){
        if(row.getValue(index1) == row.getValue(index2)){
            relationToReturn.addTuple(row);
        }
    }


    return relationToReturn;
}


Relation Relation::project(vector<int> indices) {
    Relation relationToReturn;
    relationToReturn.setHeader(this->givenHeader);

    for(auto row: this->rows){
        Tuple tupleToAdd;
        for (unsigned int i = 0; i < indices.size(); i++){
            tupleToAdd.addValue(row.getValue(indices.at(i)));
        }
        relationToReturn.addTuple(tupleToAdd);
    }


    return relationToReturn;
}

Relation Relation::rename(vector<string> attributes) {
    Relation relationToReturn;
    Header headerToReturn;
    for (unsigned int i = 0; i < attributes.size(); i++){
        headerToReturn.addToHeader(attributes.at(i));
    }
    relationToReturn.setHeader(headerToReturn);
    relationToReturn.rows = this->rows;



    return relationToReturn;
}

void Relation::setHeader(Header header) {
    this->givenHeader = header;


}

void Relation::addTuple(Tuple newTup) {
    this->rows.insert(newTup);

}

void Relation::toString() {

}
int Relation::numTuples(){
    return this->rows.size();
}

set<Tuple> Relation::getRows() {

    return this->rows;
}

Header Relation::getHeader() {

    return this->givenHeader;
}





