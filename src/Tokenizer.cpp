#include "Tokenizer.h"
#include <fstream>  // for file operations
#include <sstream>  // for string stream operations
#include <cctype>  // for character classification functions
#include <iostream> // for input/output operations

Tokenizer::Tokenizer(const std::string& filename) : filename(filename) {}

// keeps spaces, removes punctuation marks, keeps special characters (+, -, *, #)
// and digits, and converts any uppercase alphabets into lowercase
std::string Tokenizer::normalize(std::string& str) {
    for(char& c : str){
        if (c == ' '){
            continue;
        }
        else if(!isalnum(c) && c != '+' && c != '-' && c != '*' && c != '#'){
            c = ' ';
        }
        else{
            c = tolower(c);
        }
    }
    return str;
}

std::vector<std::string> Tokenizer::tokenize() {
    std::vector<std::string> tokens;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tokens; // return empty vector on error
    }

    std::string line;
    while (std::getline(file, line)) {
        line = normalize(line); // normalize the line

        std::stringstream ss(line); // separate the words using space as delimiter by default

        std::string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
    }

    return tokens;
}
