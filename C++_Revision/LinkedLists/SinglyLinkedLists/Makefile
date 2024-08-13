# Define directory paths
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

# Define compiler and flags
CXX := g++
CXXFLAGS := -I$(INCLUDE_DIR)

# Define target and dependencies
$(BIN_DIR)/LinkedListSimulation: $(OBJ_DIR)/LinkedList.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Node.o
	$(CXX) $^ -o $@ 

# Compile LinkedList.cpp
$(OBJ_DIR)/LinkedList.o: $(SRC_DIR)/LinkedList.cpp $(INCLUDE_DIR)/LinkedList.h $(INCLUDE_DIR)/Node.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/LinkedList.h $(INCLUDE_DIR)/Node.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Node.cpp
$(OBJ_DIR)/Node.o: $(SRC_DIR)/Node.cpp $(INCLUDE_DIR)/Node.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/LinkedListSimulation