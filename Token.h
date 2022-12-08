#ifndef TOKEN_H
#define TOKEN_H
#include <string>

typedef unsigned int Index;
typedef unsigned int Count;

enum class TokenType {
    COLON,
    COLON_DASH,
    ADD,
    COMMENT,
    FACTS,
    ID,
    LEFT_PAREN,
    MULTIPLY,
    PERIOD,
    Q_MARK,
    QUERIES,
    RIGHT_PAREN,
    RULES,
    SCHEMES,
    STRING,

    // TODO: add the other types of tokens
    UNDEFINED,
    COMMA,
    WHITESPACE,
    LINECOMMENT,
    ENDOFFILE
};


class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType token;
    std::string textDescription;
    unsigned int tokenLine = 0;

public:
    Token(TokenType type, std::string description, unsigned int line);

    void ToString();
    TokenType getType();
    std::string getdescription();
    unsigned int getLine();
    std::string tokenToSTring(TokenType type);


    TokenType getTypeString();
};

#endif // TOKEN_H

