CXX = clang++
CXXFLAGS = -Wall -std=c++17 -g -I src

MAIN_SRC = src/main.cpp
SQUARE_MAT_SRC = src/square_mat.cpp
TEST_SRC = tests/test_square_mat.cpp
OBJ_FILES = main.o square_mat.o
TEST_OBJ_FILES = test_square_mat.o square_mat.o

all: Main

Main: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o main

test: $(TEST_OBJ_FILES)
	$(CXX) $(TEST_OBJ_FILES) -o test_square_mat -lstdc++

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES) main test_square_mat

main.o: $(MAIN_SRC) src/square_mat.hpp
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o main.o

square_mat.o: $(SQUARE_MAT_SRC) src/square_mat.hpp
	$(CXX) $(CXXFLAGS) -c $(SQUARE_MAT_SRC) -o square_mat.o

test_square_mat.o: $(TEST_SRC) src/square_mat.hpp
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o test_square_mat.o

.PHONY: all Main test valgrind clean
