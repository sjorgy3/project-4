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

Relation Relation::unionRelation(Relation relationFromRuleEval){

    for(auto tupFromEval: relationFromRuleEval.getRows()){
        if (this->getRows().insert(tupFromEval).second){
            this->addTuple(tupFromEval);
            for(unsigned int i = 0; i < tupFromEval.getValues().size(); i++){

                cout << tupFromEval.getValues().at(i);
            }

        }
    }






}

Relation Relation::naturalJoin(Relation relationToJoin){

    Relation joinedRelation;
    Header joinedHeader;
    vector<pair<int, int>>matchingColumns;

    //start joinHeader
    joinedHeader = this->getHeader();
    for(unsigned int i = 0; i < this->getHeader().getAttributes().size(); i++){
        for(unsigned int j = 0; j < relationToJoin.getHeader().getAttributes().size(); i++){
            if (this->getHeader().getAttributes().at(i) == relationToJoin.getHeader().getAttributes().at(j)){
                matchingColumns.push_back({i,j});
            }
        }
    }
    vector<int>uniqueColInd;
    for(unsigned int i = 0; i < relationToJoin.getHeader().getAttributes().size(); i++){
        bool isUnique = true;

        for(unsigned int j=0; j < matchingColumns.size(); j++){
            if(i == matchingColumns.at(j).second){
                isUnique = false;
            }
        }
        if(isUnique == true){
            joinedHeader.addToHeader(relationToJoin.getHeader().getAttributes().at(i));
            uniqueColInd.push_back(i);
        }
    }
    joinedRelation.setHeader(joinedHeader);
    //end joinHeaders

    //start JoinTuples
    for(auto t1: this->getRows()){
        Tuple tupleToAdd = t1;
        for(auto t2:relationToJoin.getRows()){
            if(isJoinable(t1,t2,matchingColumns) == true){
                for(unsigned int i = 0; i < uniqueColInd.size(); i++){
                    tupleToAdd.addValue(t2.getValue(uniqueColInd.at(i)));
                }
            }
        }
        joinedRelation.addTuple(tupleToAdd);
    }

    return joinedRelation;
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

bool Relation::isJoinable(Tuple tuple, Tuple tuple2, vector<pair<int, int>> matchingHeader) {
    bool joinable = true;
    for(unsigned int i = 0; i < matchingHeader.size(); i++){
        if(tuple.getValues().at(matchingHeader.at(i).first) != tuple2.getValues().at(matchingHeader.at(i).second)){
            joinable = false;
        }
    }


    return joinable;
}





