#include "lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: javon-compiler <file.javon>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    for (auto& token : tokens) {
        std::cout << "Token(" << static_cast<int>(token.type)
                  << ", \"" << token.value
                  << "\", line " << token.line
                  << ", col " << token.column << ")" << std::endl;
    }

    return 0;
}
