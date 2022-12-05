#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"
#include "EOFAutomaton.h"
#include "WhiteSpaceAutomaton.h"
#include "LineCommentAutomaton.h"
#include <iostream>
using namespace std;

Lexer::Lexer() {
    CreateAutomata();

}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new EOFAutomaton());
    automata.push_back(new WhiteSpaceAutomaton());
    automata.push_back(new LineCommentAutomaton());

    // TODO: Add the other needed automata here
}

vector<Token *> Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    int inputRead = 0;
    int maxRead;
    Automaton * maxAutomatonation;
    Token * newToken;
    Token * EOFToken;

    while (!input.empty()){
        maxRead = 0;
        maxAutomatonation = automata.at(0);

        if(isspace(input.front()&& !input.empty())){
            if(input.front()=='\n'){
                lineNumber++;
            }
            input=input.substr(1);
            continue;
        }



        for(int i = 0; i < (int)automata.size(); i++){
            inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomatonation = automata.at(i);

            }


        }
        if (maxRead > 0) {
            newToken = maxAutomatonation->CreateToken(input.substr(0,maxRead),lineNumber);
            lineNumber = lineNumber + maxAutomatonation->NewLinesRead();

            if(newToken->getType() != TokenType::WHITESPACE && newToken->getType() != TokenType::COMMENT ){
                tokens.push_back(newToken);

            }



        }


        else{

            maxRead = 1;
            newToken = new Token(TokenType:: UNDEFINED, input.substr(0,1), lineNumber);
            lineNumber += maxAutomatonation->NewLinesRead();
            if(newToken->getType() != TokenType::COMMENT){
                tokens.push_back(newToken);

            }


        }
        input.erase(input.begin(),input.begin() + maxRead);



    }

    EOFToken = new Token(TokenType:: ENDOFFILE, "", lineNumber);
    tokens.push_back(EOFToken);

   /* for (int i = 0; i < (int)tokens.size(); i++){

        tokens.at(i)->ToString();

    }*/

    //cout<<"Total Tokens = " << (int)tokens.size();




    return tokens;



}
