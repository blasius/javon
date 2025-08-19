#include "ast.h"

NumberExpr::NumberExpr(double v) : value(v) {}

std::string NumberExpr::toString() const {
    return std::to_string(value);
}

BinaryExpr::BinaryExpr(std::string o, ExprPtr l, ExprPtr r)
    : op(std::move(o)), left(std::move(l)), right(std::move(r)) {}

std::string BinaryExpr::toString() const {
    return "(" + left->toString() + " " + op + " " + right->toString() + ")";
}
