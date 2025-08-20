#include <iostream>
#include<fstream>

int main() {
    std::cout << std::endl;

    std::ifstream inputFile("doc1.txt");

    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();

    std::cout << std::endl;
    
    return 0;
}