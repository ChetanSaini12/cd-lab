#include <iostream>
#include <string>
#include <unordered_map>

class LL1Parser {
private:
    std::unordered_map<std::string, std::unordered_map<char, std::string>> parsingTable;

    void initializeParsingTable() {
        // Parsing table for the grammar
        parsingTable["E"]['('] = "TE'";
        parsingTable["E"]['a'] = "TE'";
        parsingTable["E'"]['+'] = "+TE'";
        parsingTable["E'"][')'] = "";
        parsingTable["E'"]['$'] = "";
        parsingTable["T"]['('] = "FT'";
        parsingTable["T"]['a'] = "FT'";
        parsingTable["T'"]['+'] = "";
        parsingTable["T'"]['*'] = "*FT'";
        parsingTable["T'"][')'] = "";
        parsingTable["T'"]['$'] = "";
        parsingTable["F"]['('] = "(E)";
        parsingTable["F"]['a'] = "a";
    }

public:
    bool parse(const std::string& input) {
        // Initialize the parsing table
        initializeParsingTable();

        // Initialize stack
        std::string stack = "$E";
        int idx = 0;

        // Parse input
        while (idx < input.size()) {
            char symbol = stack[0];
            char nextInput = input[idx];
            if (symbol == nextInput) {
                stack.erase(0, 1);
                idx++;
            } else if (symbol >= 'A' && symbol <= 'Z') {
                std::string production = parsingTable[std::string(1, symbol)][nextInput];
                if (production.empty()) {
                    std::cerr << "Error: No production found for input '" << nextInput << "' and symbol '" << symbol << "'." << std::endl;
                    return false;
                }
                stack.erase(0, 1);
                if (production != "$") {
                    for (int i = production.size() - 1; i >= 0; i--) {
                        stack = production[i] + stack;
                    }
                }
            } else {
                std::cerr << "Error: Unexpected input '" << nextInput << "'." << std::endl;
                return false;
            }
        }

        // Check if the remaining symbols in the stack can be reduced
        while (!stack.empty()) {
            char symbol = stack[0];
            if (symbol >= 'A' && symbol <= 'Z') {
                std::string production = parsingTable[std::string(1, symbol)]['$'];
                if (production.empty()) {
                    std::cerr << "Error: No production found for symbol '" << symbol << "'." << std::endl;
                    return false;
                }
                stack.erase(0, 1);
                if (production != "$") {
                    for (int i = production.size() - 1; i >= 0; i--) {
                        stack = production[i] + stack;
                    }
                }
            } else {
                std::cerr << "Error: Unexpected symbol '" << symbol << "'." << std::endl;
                return false;
            }
        }

        return true;
    }
};

int main() {
    LL1Parser parser;

    // Test cases
    std::string input1 = "a+a*a";
    std::string input2 = "a+(a*a)";
    std::string input3 = "a*a+a";
    std::string input4 = "(a+a)*a";
    std::string input5 = "a+a*a+";

    std::cout << "Parsing " << input1 << ": " << (parser.parse(input1) ? "Accepted" : "Rejected") << std::endl;
    std::cout << "Parsing " << input2 << ": " << (parser.parse(input2) ? "Accepted" : "Rejected") << std::endl;
    std::cout << "Parsing " << input3 << ": " << (parser.parse(input3) ? "Accepted" : "Rejected") << std::endl;
    std::cout << "Parsing " << input4 << ": " << (parser.parse(input4) ? "Accepted" : "Rejected") << std::endl;
    std::cout << "Parsing " << input5 << ": " << (parser.parse(input5) ? "Accepted" : "Rejected") << std::endl;

    return 0;
}
