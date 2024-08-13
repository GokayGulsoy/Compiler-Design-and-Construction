# Define directory paths
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

# Define compiler and flags
CXX := g++
CXXFLAGS := -I$(INCLUDE_DIR)

# Define target and dependencies
$(BIN_DIR)/DoublyLinkedListSimulation: $(OBJ_DIR)/DoublyLinkedList.o $(OBJ_DIR)/main.o $(OBJ_DIR)/DoublyNode.o
	$(CXX) $^ -o $@ 

# Compile DoublyLinkedList.cpp
$(OBJ_DIR)/DoublyLinkedList.o: $(SRC_DIR)/DoublyLinkedList.cpp $(INCLUDE_DIR)/DoublyLinkedList.h $(INCLUDE_DIR)/DoublyNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/DoublyLinkedList.h $(INCLUDE_DIR)/DoublyNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile DoublyNode.cpp
$(OBJ_DIR)/DoublyNode.o: $(SRC_DIR)/DoublyNode.cpp $(INCLUDE_DIR)/DoublyNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/DoublyLinkedListSimulation
