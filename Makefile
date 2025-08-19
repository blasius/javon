CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp src/lexer/lexer.cpp src/parser/parser.cpp src/parser/ast.cpp
OUT = compiler_test

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
