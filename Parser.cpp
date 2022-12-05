//
// Created by 18017 on 10/10/2022.
//

#include <iostream>
#include "Parser.h"
#include "Token.h"
#include "Lexer.h"
using namespace std;

Parser::Parser(vector<Token *> tokensFromMain) {
    //tokens = tokensFromMain;
    for(unsigned int i = 0; i < tokensFromMain.size(); i++){
        if(tokensFromMain.at(i)->getType() != TokenType::COMMENT && tokensFromMain.at(i)->getType() != TokenType::LINECOMMENT){
            tokens.push_back(tokensFromMain.at(i));
        }
    }
}
Parser::~Parser()=default;


void Parser::match(TokenType tokenType){
    if(tokens.at(tokenLocation)->getType() == tokenType){
        tokenLocation++;
    }
    else{
        throw *tokens.at(tokenLocation);
    }

}


DatalogProgram Parser::datalogprogram(){

    //datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    try{
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        scheme();
        schemeList();
        match(TokenType::FACTS);
        match(TokenType::COLON);
        factList();
        match(TokenType::RULES);
        match(TokenType::COLON);
        ruleList();
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        query();
        queryList();
        match(TokenType::ENDOFFILE);

        object.toString();
        return object;
    }
    catch (Token error){
       /* cout << "Failure!" << endl;
        cout << "  (" << tokens.at(tokenLocation)->tokenToSTring(tokens.at(tokenLocation)->getType()) << ",\""<<  tokens.at(tokenLocation)->getdescription()<<"\","<<tokens.at(tokenLocation)->getLine() << ")";

    */return object;
    }

    }
//schemeList	->	scheme schemeList | lambda Follow = FACTS
void Parser::schemeList() {
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        scheme();
        schemeList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::FACTS){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
//factList	->	fact factList | lambda
void Parser::factList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        fact();
        factList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RULES){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::ruleList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        rule();
        ruleList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::QUERIES){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}

void Parser::queryList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        query();
        queryList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::ENDOFFILE){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::scheme(){

    newPredicate = Predicate();
    //clear newPredicate, set curr token to name in newPredicate newpred.setname=currtoken.value
    newPredicate.addName(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    //push currtoken to newPredicate vector .pushBack(param || string)
    newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    idList();
    match(TokenType::RIGHT_PAREN);

    Predicate newScheme = newPredicate;

    object.addToSchemes(newScheme);


    //cout << newPredicate.toString() << endl;

}
void Parser::fact(){

    newPredicate = Predicate();
    newPredicate.addName(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
    object.addToDomain(tokens.at(tokenLocation)->getdescription());
    match(TokenType::STRING);
    stringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);


    Predicate newFact = newPredicate;
    object.addToFacts(newFact);

   // cout << newPredicate.toString() << endl;


   /* Predicate* newFact = new Predicate();
    datalogprogram().addToFacts(*newFact);*/



}
void Parser::rule(){
    //create new rule like we created predicate
    newRule = Rule();
    headPredicate();
    match(TokenType::COLON_DASH);
    predicate();
    predicateList();
    match(TokenType::PERIOD);

    Rule ruleToAdd = newRule;
    object.addToRules(ruleToAdd);
  //  cout << newRule.toString() << endl;


}
void Parser::query(){

    newPredicate = Predicate();

    predicate();
    match(TokenType::Q_MARK);
    Predicate newQuery = newPredicate;
    object.addToQueries(newQuery);
   // cout << newPredicate.toString() << endl;

}
void Parser::headPredicate(){
    //create new predicate set it to your rule
    newPredicate = Predicate();
    newPredicate.addName(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    idList();
    match(TokenType::RIGHT_PAREN);
    newRule.addHeadPredicate(newPredicate);







}
void Parser::predicate(){
    newPredicate = Predicate();
    newPredicate.addName(tokens.at(tokenLocation)->getdescription());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parameter();
    parameterList();
    match(TokenType::RIGHT_PAREN);
    newRule.addBodyPredicate(newPredicate);



}
void Parser::predicateList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        predicate();
        predicateList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::PERIOD){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::parameterList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        parameter();
        parameterList();
    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::stringList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
        object.addToDomain(tokens.at(tokenLocation)->getdescription());
        match(TokenType::STRING);
        stringList();



    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::idList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        //push curr token back to newPred vector
        newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
        match(TokenType::ID);
        idList();


    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::parameter(){
    if (tokens.at(tokenLocation)->getType() == TokenType::STRING){
        newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
        match(TokenType::STRING);


    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::ID){
        newPredicate.addParameter(tokens.at(tokenLocation)->getdescription());
        match(TokenType::ID);
    }

    else{
        throw *tokens.at(tokenLocation);
    }
    

}





