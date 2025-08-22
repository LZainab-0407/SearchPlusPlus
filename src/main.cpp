#include <iostream>
#include<fstream>
#include "Tokenizer.h"

int main() {
    std::cout << std::endl;

    Tokenizer tokenizer("src/doc1.txt");
    std::vector<std::string> tokens = tokenizer.tokenize();

    for (const std::string& token : tokens) {
        std::cout << token << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}