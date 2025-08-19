#pragma once
#include <string>
#include <vector>

enum class TokenType {
    Number,
    Plus, Minus, Star, Slash,
    LParen, RParen,
    End
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
    std::string input;
    size_t pos = 0;

public:
    explicit Lexer(std::string text);
    std::vector<Token> tokenize();

private:
    char peek() const;
    char advance();
    void skipWhitespace();
    Token number();
};
