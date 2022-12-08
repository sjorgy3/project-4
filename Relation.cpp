//
// Created by 18017 on 11/5/2022.
//

#include <iostream>
#include "Relation.h"
#include "string"

Relation Relation::select(int index, const string& value) {
    Relation relationToReturn;
    relationToReturn.setHeader(this->givenHeader);
    for (auto row: this->rows){
        if(row.getValue(index) == value){
            relationToReturn.addTuple(row);
        }
    }


    return relationToReturn;
}

bool Relation::unionRelation(Relation relationFromRuleEval){
    bool addedTuple = false;
    set<Tuple> currentTuples = this ->getRows();
    set<Tuple> tuplesToAdd = relationFromRuleEval.getRows();
    //only producing 3 tuples to add

    for(auto tupFromEval: tuplesToAdd){

        if (this->rows.insert(tupFromEval).second){
            // this->addTuple(tupFromEval);

            addedTuple = true;

            //printing out tuple

            for(unsigned int i = 0; i < tupFromEval.getValues().size()-1; i++){
                if ( i < 1){
                    cout << "  " << this->getHeader().getAttributes().at(i) << "=";
                    cout <<tupFromEval.getValues().at(i)  << ",";
                }
                else{
                    cout << " " << this->getHeader().getAttributes().at(i) << "=";
                    cout <<tupFromEval.getValues().at(i)  << ",";                }

            }
            if(tupFromEval.getValues().size() == 1){
                cout << "  " << this->getHeader().getAttributes().at(tupFromEval.getValues().size()-1) << "=";
                cout << tupFromEval.getValue(tupFromEval.getValues().size()-1) << endl;
            }
            else{
                cout << " " << this->getHeader().getAttributes().at(tupFromEval.getValues().size()-1) << "=";
                cout << tupFromEval.getValue(tupFromEval.getValues().size()-1) << endl;
            }


        }
    }



return addedTuple;
}

Relation Relation::naturalJoin(Relation relationToJoin){

    Relation joinedRelation;
    Header joinedHeader;
    vector<pair<int, int>>matchingColumns;

    //start joinHeader
    joinedHeader = this->getHeader();
    for(unsigned int i = 0; i < this->getHeader().getAttributes().size(); i++){
        for(unsigned int j = 0; j < relationToJoin.getHeader().getAttributes().size(); j++){
            if (this->getHeader().getAttributes().at(i) == relationToJoin.getHeader().getAttributes().at(j)){
                matchingColumns.emplace_back(i,j);
            }
        }
    }
    vector<int>uniqueColInd;
    //track where you placed the unique columns within the new relation.
    for(unsigned int i = 0; i < relationToJoin.getHeader().getAttributes().size(); i++){
        bool isUnique = true;

        for(auto & matchingColumn : matchingColumns){
            if(i == matchingColumn.second){
                isUnique = false;
            }
        }
        if(isUnique){
            joinedHeader.addToHeader(relationToJoin.getHeader().getAttributes().at(i));
            uniqueColInd.push_back(i);
        }
    }
    joinedRelation.setHeader(joinedHeader);
    //end joinHeaders

    //start JoinTuples
    for(const auto& t1: this->rows){

        for(auto t2:relationToJoin.getRows()){

            if(isJoinable(t1, t2, matchingColumns)){
                Tuple tupleToAdd = t1;
                for(int i : uniqueColInd){

                    tupleToAdd.addValue(t2.getValue(i));

                }
                joinedRelation.addTuple(tupleToAdd);
            }

            //joinedRelation.addTuple(tupleToAdd);
        }

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



Relation Relation::project(const vector<int>& indices) {
    Relation relationToReturn;
    relationToReturn.setHeader(this->givenHeader);

    for(auto row: this->rows){
        Tuple tupleToAdd;
        for (int index : indices){
            tupleToAdd.addValue(row.getValue(index));
        }
        relationToReturn.addTuple(tupleToAdd);
    }


    return relationToReturn;
}

Relation Relation::rename(const vector<string>& attributes) {
    Relation relationToReturn;
    Header headerToReturn;
    for (auto & attribute : attributes){
        headerToReturn.addToHeader(attribute);
    }
    relationToReturn.setHeader(headerToReturn);
    relationToReturn.rows = this->rows;



    return relationToReturn;
}



void Relation::setHeader(const Header& header) {
    this->givenHeader = header;
}


void Relation::addTuple(const Tuple& newTup) {
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

bool Relation::isJoinable(Tuple tuple, Tuple tuple2, const vector<pair<int, int>>& matchingHeader) {
    bool joinable = true;
    for(auto & i : matchingHeader){
        if(tuple.getValues().at(i.first) != tuple2.getValues().at(i.second)){
            joinable = false;
        }
    }


    return joinable;
}





