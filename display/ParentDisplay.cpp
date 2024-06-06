#include "../include/ParentDisplay.h"

string ParentDisplay::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');

    if (first == string::npos) {
        return "";
    }

    size_t last = str.find_last_not_of(' ');

    return str.substr(first, last - first + 1);
}

string ParentDisplay::getInput(const string& prompt) {
    string input;
    while (true) {
        std::cout << prompt;
        getline(cin, input);
        input = trim(input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Input cannot be empty. Please enter a valid value." << endl;
    }
}