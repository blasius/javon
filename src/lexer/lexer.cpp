#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(std::string text) : input(std::move(text)) {}

char Lexer::peek() const {
    return pos < input.size() ? input[pos] : '\0';
}

char Lexer::advance() {
    return pos < input.size() ? input[pos++] : '\0';
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek())) advance();
}

Token Lexer::number() {
    std::string num;
    while (std::isdigit(peek())) num += advance();
    return {TokenType::Number, num};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (true) {
        skipWhitespace();
        char c = peek();
        if (c == '\0') { tokens.push_back({TokenType::End, ""}); break; }
        if (std::isdigit(c)) { tokens.push_back(number()); continue; }

        switch (advance()) {
            case '+': tokens.push_back({TokenType::Plus, "+"}); break;
            case '-': tokens.push_back({TokenType::Minus, "-"}); break;
            case '*': tokens.push_back({TokenType::Star, "*"}); break;
            case '/': tokens.push_back({TokenType::Slash, "/"}); break;
            case '(': tokens.push_back({TokenType::LParen, "("}); break;
            case ')': tokens.push_back({TokenType::RParen, ")"}); break;
            default: throw std::runtime_error("Unexpected character");
        }
    }
    return tokens;
}
