#include <iostream>
#include <cstring>  
#include <cctype>   
using namespace std;
enum class TokenType {

    IDENTIFIER,
    OPERATOR,
    NUMBER,
    INT,
    FLOAT,
    While,
    For,
    String,
    Char,
    SEMICOLON,
    PARENTHESIS,
    BRACE,
    BRACKET,
    ASSIGN,
    COMPARISON,
    LE_COMPARISON,
    RE_COMPARISON,
    END,
    UNKNOWN
};
struct Token {
    TokenType type;
    char lexeme[50];
};
bool isIdentifier(const char* str) {
    if (str[0] == '\0') return false;
    if (!(isalpha(str[0]) || str[0] == '_')) return false;
    if (strcmp(str, "int") == 0) return false;
    if (strcmp(str, "for") == 0) return false;
    if (strcmp(str, "while") == 0) return false;
    if (strcmp(str, "float") == 0) return false;
    if (strcmp(str, "string") == 0) return false;
    if (strcmp(str, "char") == 0) return false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) return false;
    }
    return true;
}
bool isNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}
bool isFloatLiteral(const char* str) {
    bool foundDot = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (foundDot) return false;
            foundDot = true;
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }
    return foundDot;
}
bool isIntLiteral(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}
void OPERATORTYPE(char currentChar) {
    cout << "Lexeme: '" << currentChar << "', Token Type: ";
    if (currentChar == '+') {
        cout << "plus_op";
    }
    else if (currentChar == '-') {
        cout << "sub_op";
    }
    else if (currentChar == '*') {
        cout << "mult_op";
    }
    else if (currentChar == '/') {
        cout << "div_op";
    }
    else if (currentChar == '=') {
        cout << "assign_op";
    }
    else if (currentChar == '(') {
        cout << "lparen";
    }
    else if (currentChar == ')') {
        cout << "rparen";
    }
    else if (currentChar == '{') {
        cout << "lbrace";
    }
    else if (currentChar == '}') {
        cout << "rbrace";
    }
    else if (currentChar == '[') {
        cout << "lbrack";
    }
    else if (currentChar == ']') {
        cout << "rbrack";
    }
    else if (currentChar == ';') {
        cout << "semicolon";
    }
    else if (currentChar == 'int') {
        cout << "reserv_word";
    }
    else {
        cout << "unknown_op";
    }
    cout << endl;
}
void tokenize(const char* input) {
    char lexeme[50];
    int lexemeIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        char currentChar = input[i];

        if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
            if (lexemeIndex > 0) {
                lexeme[lexemeIndex] = '\0';

                if (isIdentifier(lexeme)) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: IDENTIFIER" << endl;
                }
                else if (strcmp(lexeme, "int") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: INT" << endl;
                }
                else if (strcmp(lexeme, "for") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: FOR" << endl;
                }
                else if (strcmp(lexeme, "while") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: while" << endl;
                }
                else if (strcmp(lexeme, "float") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: Resirved_word" << endl;
                }
                else if (strcmp(lexeme, "string") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: Resirved_word" << endl;
                }
                else if (strcmp(lexeme, "char") == 0) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: Resirved_word" << endl;
                }
                else if (isFloatLiteral(lexeme)) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: FLOAT_LITERAL" << endl;
                }
                else if (isIntLiteral(lexeme)) {
                    cout << "Lexeme: '" << lexeme << "', Token Type: INT_LITERAL" << endl;
                }
                else {
                    cout << "Lexeme: '" << lexeme << "', Token Type: UNKNOWN" << endl;
                }
                lexemeIndex = 0;
            }
            continue;
        }
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' ||
            currentChar == '=' || currentChar == '(' || currentChar == ')' || currentChar == ';' ||
            currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']') {
            if (lexemeIndex > 0) {
                lexeme[lexemeIndex] = '\0';
                cout << "Lexeme: '" << lexeme << "', Token Type: IDENTIFIER" << endl;
                lexemeIndex = 0;
            }
            OPERATORTYPE(currentChar);
            continue;
        }
        if (currentChar == '=' && input[i + 1] == '=') {
            cout << "Lexeme: '==' , Token Type: COMPARISON" << endl;
            i++;
            continue;
        }
        else if (currentChar == '<' && input[i + 1] == '=') {
            cout << "Lexeme: '<=', Token Type: LE_COMPARISON" << endl;
            i++;
            continue;
        }
        else if (currentChar == '>' && input[i + 1] == '=') {
            cout << "Lexeme: '>=', Token Type: RE_COMPARISON" << endl;
            i++;
            continue;
        }


        lexeme[lexemeIndex++] = currentChar;
    }
    if (lexemeIndex > 0) {
        lexeme[lexemeIndex] = '\0';
        if (isIdentifier(lexeme)) {
            cout << "Lexeme: '" << lexeme << "', Token Type: IDENTIFIER" << endl;
        }
        else if (isFloatLiteral(lexeme)) {
            cout << "Lexeme: '" << lexeme << "', Token Type: FLOAT" << endl;
        }
        else if (isIntLiteral(lexeme)) {
            cout << "Lexeme: '" << lexeme << "', Token Type: INT" << endl;
        }
        else {
            cout << "Lexeme: '" << lexeme << "', Token Type: UNKNOWN" << endl;
        }
    }
}
int main() {
    char input[200];
    cout << "Enter a code snippet: ";
    cin.getline(input, 200);

    tokenize(input);

    return 0;
}
