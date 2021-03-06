//TODO: Implement interfaces for deletion and searching

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isOperator(char);
bool isAlphabet(char);
bool isDigit(char);
bool isIdentifier(const char *, int, int);
void printSymbolTableEntry(const char*, int, int, const char*);
int addToSymbolTable(const char*, int, int, const char*);
void printSymbolTable();

struct SymbolTable {
    char symbol[20];
    void *address;
    char type[20];
} symbolTable[20];

int symbolTableIndex = -1;

int main() {
    char str[100];
    int i = 0, j = 0, *p = &symbolTableIndex;

    printf("Enter an string: ");
    scanf("%[^\n]s", str);

    printf("You entered: %s\n\n", str);

    for (i = 0; str[i] != NULL; ++i) {

        while (str[i] == ' ') {
            i++;
        }

        if (!isOperator(str[i])) {
            for (j = i; !isOperator(str[j]) && str[j] != NULL && str[j] != ' '; ++j);
            if(isIdentifier(str, i, j-1)) {
                addToSymbolTable(str, i, j-1, "identifier");
            }
            i=j-1;
        }
    }

    printSymbolTable();

    return 0;
}

bool isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '=');
}

void printSymbolTableEntry(const char *ptr, int start, int end, const char *type) {
    for (int i = start; i <= end; ++i) {
        printf("%c", ptr[i]);
    }
    printf("\t\t\t\t%p\t\t\t%s\n", (void *) (ptr + start), type);
}

int addToSymbolTable(const char *ptr, int start, int end, const char *type) {

    int i;
    char *tempStr = malloc(20*sizeof(char));

    for (int j = start; j <= end ; ++j) {
        tempStr[j-start] = ptr[j];
    }
    tempStr[end - start + 1] = '\0';

    for (i = 0; i <= symbolTableIndex; ++i) {
<<<<<<< HEAD
        if (!strcmp(symbolTable[i].symbol, tempStr)) {
            free(tempStr);
            return i;
        }
=======
        if (!strcmp(symbolTable[i].symbol, tempStr))
            return i;
>>>>>>> 5c04b7491653d95f1ac84128df9aedaf2ae81a97
    }

    symbolTableIndex++;
    strcpy(symbolTable[symbolTableIndex].symbol, tempStr);
    symbolTable[symbolTableIndex].address = (void *) ptr + start;
    strcpy(symbolTable[symbolTableIndex].type, type);
<<<<<<< HEAD

    free(tempStr);

    return symbolTableIndex;
=======
>>>>>>> 5c04b7491653d95f1ac84128df9aedaf2ae81a97
}

void printSymbolTable() {
    printf("Symbol\t\t\tAddress\t\t\t\t\tType\n\n");

    struct SymbolTable currentSymbol;

    for (int i = 0; i <= symbolTableIndex; ++i) {
        currentSymbol = symbolTable[i];
        printf("%s\t\t\t\t%p\t\t\t%s\n", currentSymbol.symbol,
                currentSymbol.address, currentSymbol.type);
    }
}

bool isIdentifier(const char* token, int start, int end) {

    if (isAlphabet(token[start]) || token[start] == '_') {
        for (int i = start; i <= end ; ++i) {
            if (!isAlphabet(token[i]) && token[i] != '_' && !isDigit(token[i]))
                return false;
        }
        return true;
    }
    else
        return false;
}

bool isAlphabet(char c) {
    if(tolower(c) >= 'a' && tolower(c) <= 'z')
        return true;
    else
        return false;
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}