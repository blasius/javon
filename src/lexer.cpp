#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source)
    : source(source), position(0), line(1), column(1) {}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source[position];
}

char Lexer::get() {
    char c = peek();
    position++;
    if (c == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    return c;
}

bool Lexer::isAtEnd() const {
    return position >= source.size();
}

void Lexer::skipWhitespace() {
    while (!isAtEnd() && std::isspace(peek())) get();
}

Token Lexer::identifier() {
    int startColumn = column;
    std::string value;
    while (!isAtEnd() && (std::isalnum(peek()) || peek() == '_')) {
        value += get();
    }

    // Simple keyword recognition
    if (value == "class" || value == "public" || value == "static" || value == "void" || value == "int") {
        return {TokenType::Keyword, value, line, startColumn};
    }

    return {TokenType::Identifier, value, line, startColumn};
}

Token Lexer::number() {
    int startColumn = column;
    std::string value;
    while (!isAtEnd() && std::isdigit(peek())) {
        value += get();
    }
    return {TokenType::Number, value, line, startColumn};
}

Token Lexer::punctuationOrOperator() {
    int startColumn = column;
    std::string value(1, get());
    return {TokenType::Punctuation, value, line, startColumn};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!isAtEnd()) {
        skipWhitespace();
        if (isAtEnd()) break;

        char c = peek();

        if (std::isalpha(c) || c == '_') {
            tokens.push_back(identifier());
        } else if (std::isdigit(c)) {
            tokens.push_back(number());
        } else {
            tokens.push_back(punctuationOrOperator());
        }
    }
    tokens.push_back({TokenType::EndOfFile, "", line, column});
    return tokens;
}
