#pragma once
#include <memory>
#include <string>

struct Expr {
    virtual ~Expr() = default;
    virtual std::string toString() const = 0;
};

using ExprPtr = std::unique_ptr<Expr>;

struct NumberExpr : Expr {
    double value;
    explicit NumberExpr(double v);
    std::string toString() const override;
};

struct BinaryExpr : Expr {
    std::string op;
    ExprPtr left, right;

    BinaryExpr(std::string o, ExprPtr l, ExprPtr r);
    std::string toString() const override;
};
