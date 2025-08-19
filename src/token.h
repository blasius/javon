#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    Identifier,
    Keyword,
    Number,
    Operator,
    Punctuation,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

#endif
