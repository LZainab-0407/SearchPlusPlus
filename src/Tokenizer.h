#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>

class Tokenizer {
public:
    // constructor with filename
    Tokenizer(const std::string& filename);

    //method to read the file and tokenize its content
    std::vector<std::string> tokenize();

private:
    std::string filename;

    // helper method to normalize a string 
    std::string normalize(std::string& str);
};

#endif // TOKENIZER_H