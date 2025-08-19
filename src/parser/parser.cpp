#include "parser.h"

Parser::Parser(std::vector<Token> tks) : tokens(std::move(tks)) {}

const Token& Parser::peek() const {
    return tokens[pos];
}

const Token& Parser::advance() {
    return tokens[pos++];
}

bool Parser::match(TokenType type) {
    if (peek().type == type) { advance(); return true; }
    return false;
}

ExprPtr Parser::parseExpression() { return parseTerm(); }

ExprPtr Parser::parseTerm() {
    ExprPtr expr = parseFactor();
    while (peek().type == TokenType::Plus || peek().type == TokenType::Minus) {
        std::string op = peek().lexeme;
        advance();
        expr = std::make_unique<BinaryExpr>(op, std::move(expr), parseFactor());
    }
    return expr;
}

ExprPtr Parser::parseFactor() {
    ExprPtr expr = parsePrimary();
    while (peek().type == TokenType::Star || peek().type == TokenType::Slash) {
        std::string op = peek().lexeme;
        advance();
        expr = std::make_unique<BinaryExpr>(op, std::move(expr), parsePrimary());
    }
    return expr;
}

ExprPtr Parser::parsePrimary() {
    if (peek().type == TokenType::Number) {
        double val = std::stod(peek().lexeme);
        advance();
        return std::make_unique<NumberExpr>(val);
    }
    if (match(TokenType::LParen)) {
        ExprPtr expr = parseExpression();
        if (!match(TokenType::RParen))
            throw std::runtime_error("Expected ')'");
        return expr;
    }
    throw std::runtime_error("Unexpected token: " + peek().lexeme);
}

ExprPtr Parser::parse() {
    return parseExpression();
}
