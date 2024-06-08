#include <iostream>
#include <fstream>
#include <sstream>

#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"


int main() {
    // Open the input file
    std::ifstream inputFile("testinput.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    // Vector to store the instructions
    std::vector<int> instructions;

    // Read the input file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string command;
        int value;
        iss >> command;
        if (command == "insert") {
            iss >> value;
            instructions.push_back(value);
        } else if (command == "pop") {
            // For pop median operation, push -1 to the back of the vector
            instructions.push_back(-1);
        }
    }

    // Close the input file
    inputFile.close();

    //Test cases
    vectorMedian(&instructions);
    listMedian(&instructions);
    heapMedian(&instructions);
    treeMedian(&instructions);

  return 0;


}