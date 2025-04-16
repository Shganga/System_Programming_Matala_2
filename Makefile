# Compiler and Flags
CXX = clang++
CXXFLAGS = -Wall -std=c++17 -g -I src  # Add the src directory to the include search path

# Files
MAIN_SRC = src/main.cpp
SQUARE_MAT_SRC = src/square_mat.cpp  # Changed to lowercase snake_case
TEST_SRC = tests/test_square_mat.cpp  # Changed to lowercase snake_case
OBJ_FILES = main.o square_mat.o  # Changed to lowercase snake_case
TEST_OBJ_FILES = test_square_mat.o square_mat.o  # Changed to lowercase snake_case

# Targets
all: Main

# Main target - compiles the main program
Main: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o main

# Test target - compiles the test program
test: $(TEST_OBJ_FILES)
	$(CXX) $(TEST_OBJ_FILES) -o test_square_mat -lstdc++

# Valgrind target - runs valgrind on the program
valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./main

# Clean target - removes all compiled files
clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES) main test_square_mat

# Compilation for the main program
main.o: $(MAIN_SRC) src/square_mat.hpp  # Changed to lowercase snake_case
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o main.o

square_mat.o: $(SQUARE_MAT_SRC) src/square_mat.hpp  # Changed to lowercase snake_case
	$(CXX) $(CXXFLAGS) -c $(SQUARE_MAT_SRC) -o square_mat.o

# Compilation for the test program
test_square_mat.o: $(TEST_SRC) src/square_mat.hpp  # Changed to lowercase snake_case
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o test_square_mat.o

# Phony targets to prevent make from confusing them with filenames
.PHONY: all Main test valgrind clean
