#pragma once
#include "../lexer/lexer.h"
#include "ast.h"
#include <vector>
#include <stdexcept>

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

    const Token& peek() const;
    const Token& advance();
    bool match(TokenType type);

    ExprPtr parseExpression();
    ExprPtr parseTerm();
    ExprPtr parseFactor();
    ExprPtr parsePrimary();

public:
    explicit Parser(std::vector<Token> tks);
    ExprPtr parse();
};
