#include "Token.h"
#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



Token::Token(TokenType type, std::string description, int line) {
    token = type;
    textDescription = description;
    tokenLine = line;


}

void Token::ToString() {
   //cout << "(" << tokenToSTring(getType()) << ",\"" << getdescription() << "\"," << getLine() << ")" << endl;


}

TokenType Token::getType() {
    return token;
}


std::string Token::getdescription() {
    return textDescription;
}

int Token::getLine() {
    return tokenLine;
}

std::string Token::tokenToSTring(TokenType type) {
    switch(type){
        default:
        case TokenType::SCHEMES: return "SCHEMES"; break;
        case TokenType::FACTS: return "FACTS"; break;
        case TokenType::ADD: return "ADD"; break;
        case TokenType::COMMENT: return "COMMENT"; break;
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::COMMA: return "COMMA"; break;
        case TokenType::ID: return "ID"; break;
        case TokenType::LEFT_PAREN: return "LEFT_PAREN"; break;
        case TokenType::MULTIPLY: return "MULTIPLY"; break;
        case TokenType::PERIOD: return "PERIOD"; break;
        case TokenType::Q_MARK: return "Q_MARK"; break;
        case TokenType::QUERIES: return "QUERIES"; break;
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN"; break;
        case TokenType::RULES: return "RULES"; break;
        case TokenType::STRING: return "STRING"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;
        case TokenType::ENDOFFILE: return "EOF"; break;
        case TokenType::WHITESPACE: return "WHITESPACE"; break;
        case TokenType::LINECOMMENT: return "COMMENT"; break;
    }

}
