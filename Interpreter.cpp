//
// Created by 18017 on 11/5/2022.
//

#include <iostream>
#include "Interpreter.h"

void Interpreter::intepretSchemes() {
    for (auto &&scheme:program.getSchemes()) {
        Header newHeader;
        for (Index i = 0; i < scheme.getParams().size(); ++i) {
            newHeader.addToHeader(scheme.getParams().at(i).toString());
        }
        Relation newRelation(scheme.getName(), newHeader);
        database.addRelation(newRelation);

    }


}

void Interpreter::interpretFacts() {
    for (auto &&fact:program.getFacts()) {
        Tuple newTuple;
        for (unsigned int i = 0; i < fact.getParams().size(); i++) {
            newTuple.addValue(fact.getParams().at(i).toString());

        }
        database.getRelation2(fact.getName())->addTuple(newTuple);
    }

}


void Interpreter::interpretQueries() {
    cout << "Query Evaluation" << endl;
    for (auto &&query:program.getQueries()) {
        cout << query.toString() << "?" << " ";

        Relation relationCopy = database.getRelationCopy(query.getName());

        map<string, int> variables;
        vector<string> values;
        vector<unsigned int> indices;


        for (unsigned int i = 0; i < query.getParams().size(); i++) {
            if (query.getParams().at(i).isConstant()) {
                relationCopy = relationCopy.select(i, query.getParams().at(i).toString());
            } else {
                if (variables.find(query.getParams().at(i).toString()) != variables.end()) {
                    relationCopy = relationCopy.select2(variables[query.getParams().at(i).toString()], i);

                } else {
                    variables.insert({query.getParams().at(i).toString(), i});
                    values.push_back(query.getParams().at(i).toString());
                    indices.push_back(i);

                }
            }

        }

        relationCopy = relationCopy.project(indices);

        relationCopy = relationCopy.rename(values);

        if (relationCopy.numTuples() > 0) {
            cout << "Yes" << "(" << relationCopy.numTuples() << ")" << endl;
            for (auto t: relationCopy.getRows()) {
                if (!relationCopy.getHeader().getAttributes().empty()) {

                    for (unsigned int i = 0; i < t.getValues().size() - 1; ++i) {
                        if (i < 1) {
                            cout << "  " << relationCopy.getHeader().getAttributes().at(i) << "=";
                            cout << t.getValue(i) << ",";
                        } else {
                            cout << " " << relationCopy.getHeader().getAttributes().at(i) << "=";
                            cout << t.getValue(i) << ",";
                        }


                    }
                    if (t.getValues().size() == 1) {
                        cout << "  " << relationCopy.getHeader().getAttributes().at(t.getValues().size() - 1) << "=";
                        cout << t.getValue(t.getValues().size() - 1) << endl;
                    } else {
                        cout << " " << relationCopy.getHeader().getAttributes().at(t.getValues().size() - 1) << "=";
                        cout << t.getValue(t.getValues().size() - 1) << endl;
                    }
                }

            }
        } else {
            cout << "No" << endl;

        }
    }
}

Relation Interpreter::interpretPredicate(Predicate predicate) {
    Relation relationCopy = database.getRelationCopy(predicate.getName());
    map<string, int> variables;
    vector<string> values;
    vector<unsigned int> indices;


    for (unsigned int i = 0; i < predicate.getParams().size(); i++) {
        if (predicate.getParams().at(i).isConstant()) {
            relationCopy = relationCopy.select(i, predicate.getParams().at(i).toString());
        } else {
            if (variables.find(predicate.getParams().at(i).toString()) != variables.end()) {
                relationCopy = relationCopy.select2(variables[predicate.getParams().at(i).toString()], i);

            } else {
                variables.insert({predicate.getParams().at(i).toString(), i});
                values.push_back(predicate.getParams().at(i).toString());
                indices.push_back(i);


            }

        }


    }


    relationCopy = relationCopy.project(indices);

    relationCopy = relationCopy.rename(values);

    return relationCopy;
}

vector<unsigned int> Interpreter::projectInd(Rule currRule, Header targRule) {
    vector<unsigned int> indToProject;
    for (unsigned int i = 0; i < currRule.getHeadPredicate().getParams().size(); i++) {
        for (unsigned int j = 0; j < targRule.getAttributes().size(); ++j) {
            if (currRule.getHeadPredicate().getParams().at(i).toString() == targRule.getAttributes().at(j)) {
                indToProject.push_back(j);
            }
        }
    }


    return indToProject;

}

void Interpreter::interpretRules() {


    cout << "Rule Evaluation" << endl;
    bool modified = true;
    unsigned int numPasses = 0;
    while (modified) {
        modified = false;

        for (auto rule : program.getRules()) {
            cout << rule.toString() << "." << endl;
            //Evaluate right hand side predicate
            vector<Relation> vecRel;
            vector<Predicate> predList = rule.getBodyPredicates();
            Relation origRelation = this->database.getRelationCopy(rule.getHeadPredicate().getName());
            Relation finalRelation;

            for (auto p : predList) {
                Relation evalRelation = interpretPredicate(p);
                vecRel.push_back(evalRelation);


            }

            //join the relations together
            if (vecRel.size() == 1) {
                finalRelation = vecRel.at(0);
            } else if (vecRel.size() > 1) {
                for (unsigned int i = 0; i < vecRel.size() - 1; ++i) {
                    vecRel.at(i + 1) = vecRel.at(i).naturalJoin(vecRel.at(i + 1));
                    finalRelation = vecRel.at(i + 1);
                }
            }

            vector<unsigned int> projInd = projectInd(rule, finalRelation.getHeader());
            //project

            finalRelation = finalRelation.project(projInd);




            //rename
            finalRelation = finalRelation.rename(origRelation.getHeader().getAttributes());
            //union
            if(!modified){
                modified = origRelation.unionRelation(finalRelation);
            }
            else{
                origRelation.unionRelation(finalRelation);
            }



            *this->database.getRelation2(origRelation.getName()) = origRelation;

            // modified = this->database.getRelation2(finalRelation.getName())->unionRelation(finalRelation);

        }
        numPasses++;
    }
    cout << endl << "Schemes populated after " << numPasses << " passes through the Rules." << endl << endl;
}


Database Interpreter::database1() {
    intepretSchemes();
    interpretFacts();
    interpretRules();
    interpretQueries();


    return this->database;
}


