#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **commonChars(char **words, int wordsSize, int *returnSize) {
    int hash[26] = {0};
    int currentIndex = 0;

    for (char *c = words[0]; *c ; c++) {
        hash[*c - 'a'] += 1;
    }

    for (int i = 1; i < wordsSize; i++) {
        int currentHash[26] = {0};
        for (char *c = words[i]; *c; c++) {
            currentHash[*c - 'a'] += 1;
        }
        for (int j = 0; j < 26; j++) {
            hash[j] = (hash[j] < currentHash[j]) ? hash[j] : currentHash[j];
        }
    }

    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        *returnSize += hash[i];
    }

    char **ret = malloc((*returnSize + 1) * sizeof(char*));
    if (!ret) return 0;

    currentIndex = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < hash[i]; j++) {
            ret[currentIndex] = malloc(2 * sizeof(char));
            if (!ret[currentIndex]) return 0;
            ret[currentIndex][0] = i + 'a';
            ret[currentIndex][1] = 0;
            currentIndex++;
        }
    }
    ret[currentIndex] = 0;
    return ret;
}






void printResult(char **result) {
    if (result == NULL) {
        printf("No common characters found.\n");
        return;
    }
    for (int i = 0; result[i] != NULL; i++) {
        printf("\"%s\"", result[i]);
        if (result[i + 1] != NULL) {
            printf(", ");
        }
    }
    printf("\n");
}


// Testing
int main() {

   char *words[][5] = {
        {"bella", "label", "roller", NULL, NULL},
        {"cool", "lock", "cook", NULL, NULL},
        {"abc", "def", "ghi", NULL, NULL},
        {"abcd", "efgh", "ijkl", NULL, NULL},
        {NULL}
    };

    for (int i = 0; words[i][0] != NULL; i++) {
        int wordsSize = 0;
        while (words[i][wordsSize] != NULL) {
            wordsSize++;
        }
        
        int returnSize;
        char **result = commonChars(words[i], wordsSize, &returnSize);
        printf("Common characters in test case %d: ", i + 1);
        printResult(result);
        
        for (int j = 0; j < returnSize; j++) {
            free(result[j]);
        }
        free(result);
    }

    return 0;
}