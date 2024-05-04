#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isValidKeyword(const string& word) {
    string keywords[] = {"int", "if", "else", "for", "while", "return", "using", "namespace", "cout", "cin"};
    for (const string& keyword : keywords) {
        if (word == keyword) {
            return true;
        }
    }
    return false;
}

bool isValidDataType(const string& word) {
    string dataTypes[] = {"int", "char", "bool", "float", "double"};
    for (const string& dataType : dataTypes) {
        if (word == dataType) {
            return true;
        }
    }
    return false;
}

bool isValidIdentifier(const string& word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }
    for (char c : word) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

bool isValidOperator(const char& op) {
    string operators = "+-*/%=><&|!^";
    return operators.find(op) != string::npos;
}

bool isPunctuation(const char& ch) {
    string punctuations = "{}[]();,";
    return punctuations.find(ch) != string::npos;
}

bool isValidHeader(const string& line) {
    size_t pos = line.find("#include");
    return pos != string::npos && pos == 0;
}

bool isValidNamespace(const string& line) {
    size_t pos = line.find("using namespace");
    return pos != string::npos && pos == 0;
}

int main() {
    ifstream file("C:\\New folder\\lex_input.txt");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        cout << "Line " << lineNumber << ":\n";
        lineNumber++;

        // Check for header file declaration
        if (isValidHeader(line)) {
            cout << "Header file declaration\n ";
        }

        // Check for namespace declaration
        else if (isValidNamespace(line)) {
            cout << "Namespace declaration\n";
        }

        // Tokenize line
        string word = "";
        for (char c : line) {
            if (isspace(c)) {
                // Check for keyword
                if (isValidKeyword(word)) {
                    cout << "Built-in keyword: " << word << endl;
                }
                // Check for data type
                else if (isValidDataType(word)) {
                    cout << "Datatype: " << word << endl;
                }
                // Check for identifier
                else if (isValidIdentifier(word)) {
                    cout << "Identifier: " << word << endl;
                }
                // Check for constant
                else if (!word.empty() && (word[0] == '"' || isdigit(word[0]))) {
                    cout << "Constant: " << word << endl;
                }
                word = "";
            } else if (isValidOperator(c)) {
                cout << "Operator: " << c << endl;
            } else if (isPunctuation(c)) {
                cout << "Punctuation: " << c << endl;
            } else {
                word += c;
            }
        }
    }

    file.close();
    return 0;
}
