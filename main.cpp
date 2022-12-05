#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "Interpreter.h"
#include <vector>

using namespace std;


int main(int argc, char** argv) {

    ifstream infile(argv[1]);

    string text, line;
    while(getline(infile, line))
    {
        text += line + '\n';
    }


    infile.close();



    Lexer* lexer = new Lexer();
    vector<Token*>tokenVector = lexer->Run(text);
    Parser* parser = new Parser(tokenVector);
    Interpreter* interpreter = new Interpreter(parser->datalogprogram());
    interpreter->database1();








    delete lexer;

    return 0;
}