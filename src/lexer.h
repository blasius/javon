#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    char peek() const;
    char get();
    bool isAtEnd() const;

    void skipWhitespace();
    Token identifier();
    Token number();
    Token punctuationOrOperator();

    std::string source;
    size_t position;
    int line;
    int column;
};

#endif
