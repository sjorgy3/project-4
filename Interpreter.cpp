//
// Created by 18017 on 11/5/2022.
//

#include <iostream>
#include "Interpreter.h"

void Interpreter::intepretSchemes() {
    for(auto &&scheme:program.getSchemes()){
        Header newHeader;
        for (unsigned int i = 0; i < scheme.getParams().size(); ++i) {
            newHeader.addToHeader(scheme.getParams().at(i).toString());
        }
        Relation newRelation(scheme.getName(),newHeader);
        database.addRelation(newRelation);

    }



}

void Interpreter::interpretFacts() {
    for(auto &&fact:program.getFacts()){
        Tuple newTuple;
        for (unsigned int i = 0; i < fact.getParams().size(); i++){
            newTuple.addValue(fact.getParams().at(i).toString());

        }
        database.getRelation2(fact.getName())->addTuple(newTuple);
    }

}



void Interpreter::interpretQueries() {

for(auto &&query:program.getQueries()){
    cout << query.toString() << "?" << " ";

    Relation relationCopy =  database.getRelationCopy(query.getName());

    map<string,int>variables;
    vector<string>values;
    vector<int>indices;


    for(unsigned int i = 0; i < query.getParams().size(); i++){
       if (query.getParams().at(i).isConstant() == true){
           relationCopy = relationCopy.select(i,query.getParams().at(i).toString());


       }

       else{
           if(variables.find(query.getParams().at(i).toString()) != variables.end()){
              relationCopy= relationCopy.select2(variables[query.getParams().at(i).toString()], i);

           }
           else{
               variables.insert({query.getParams().at(i).toString(), i});
               values.push_back(query.getParams().at(i).toString());
               indices.push_back(i);

           }
       }

   }

    relationCopy = relationCopy.project(indices);

    relationCopy = relationCopy.rename(values);

    if(relationCopy.numTuples() > 0){
        cout << "Yes" << "(" << relationCopy.numTuples() << ")" << endl;
        for(auto t: relationCopy.getRows()){
            if(!relationCopy.getHeader().getAttributes().empty()){

                for (unsigned int i = 0; i < t.getValues().size()-1; ++i) {
                    if ( i < 1) {
                        cout << "  " << relationCopy.getHeader().getAttributes().at(i) << "=";
                        cout << t.getValue(i) << ",";
                    }
                    else{
                        cout << " " << relationCopy.getHeader().getAttributes().at(i) << "=";
                        cout << t.getValue(i) << ",";
                    }


                }
                if(t.getValues().size() == 1){
                    cout << "  " << relationCopy.getHeader().getAttributes().at(t.getValues().size()-1) << "=";
                    cout << t.getValue(t.getValues().size()-1) << endl;
                }
                else {
                    cout << " " << relationCopy.getHeader().getAttributes().at(t.getValues().size() - 1) << "=";
                    cout << t.getValue(t.getValues().size() - 1) << endl;
                }
            }

        }
    }
    else{
        cout << "No" << endl;

    }



}



}
void Interpreter::interpretRules() {

}

Database Interpreter::database1() {
    intepretSchemes();
    interpretFacts();
    interpretQueries();


    return this->database;
}

void Interpreter::interpret() {
    database1();

}

