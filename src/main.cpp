#include "lexer/lexer.h"
#include "parser/parser.h"
#include <iostream>

int main() {
    std::string input = "3 + 4 * (2 - 1)";
    Lexer lexer(input);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    ExprPtr ast = parser.parse();

    std::cout << "Input: " << input << std::endl;
    std::cout << "AST:   " << ast->toString() << std::endl;
    return 0;
}
