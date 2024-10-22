#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* restoreString(char* s, int* indices, int indicesSize) {
    int len = strlen(s);
    char* newStr = malloc(strlen(s) + 1);
    if (!newStr) {
        return 0;
    }

    newStr[len] = 0;
    for (int i = 0; i < indicesSize; i++) {
        newStr[indices[i]] = s[i];
    }

    strcpy(s, newStr);
    free(newStr);
    return s;
}

// Testing
int main() {
    // Hopefully i dont forget to complete this
    return 0;
}