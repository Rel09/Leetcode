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
    // Test strings
    char    *strings[]      = { "abc", "ebc", NULL };
    int     *intptr[]       = { {2, 1, 0}, {0, 2, 1} };
    int     indicesSizes[]   = { 3, 3 };

    char    *Expected[]     = { "cba", "ebc" };

    // Loop through each test case
    for (int i = 0; strings[i]; i++) {
        printf("%s\n", strings[i]);

        for (int j = 0; j < indicesSizes[i]; j++) {
            printf("---> %i\n", intptr[i][j]);
        }

        printf("%i\n", indicesSizes[i]);
    }

    return 0;
}