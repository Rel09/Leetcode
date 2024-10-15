#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int index;
    int height;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personB->height - personA->height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    Person *people = alloca(namesSize * sizeof(Person));
    //Person *people = malloc(namesSize * sizeof(Person));
    for (int i = 0; i < namesSize; i++) {
        people[i].index = i;
        people[i].height = heights[i];
    }

    qsort(people, namesSize, sizeof(Person), compare);

    char** ret = malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        ret[i] = strdup(names[people[i].index]);
    }

    //free(people);
    *returnSize = namesSize;
    return ret;
}

// Testing
int main() {
     char *testNames[][3] = {
        {"Alice", "Bob", "Charlie"},
        {"Tom", "Jerry", "Spike"},
        {"Anna", "Elsa", "Olaf"},
        {"John", "Doe", "Jane"},
        {"Zara", "Mike", "Lucy"},
        {"Chris", "Robin", "Peter"},
    };
    
    int testHeights[][3] = {
        {150, 180, 165},
        {170, 160, 180},
        {140, 160, 120},
        {175, 160, 170},
        {190, 175, 165},
        {180, 170, 160},
    };

    char *expectedResults[][3] = {
        { "Bob", "Charlie", "Alice" },
        { "Spike", "Tom", "Jerry" },
        { "Elsa", "Anna", "Olaf" },
        { "John", "Jane", "Doe" },
        { "Zara", "Mike", "Lucy" },
        { "Chris", "Robin", "Peter" },
    };

    int numTests = sizeof(testNames) / sizeof(testNames[0]);
    
    for (int i = 0; i < numTests; i++) {
        int returnSize;
        char **sortedNames = sortPeople(testNames[i], 3, testHeights[i], 3, &returnSize);

        printf("Test case %d: ", i + 1);
        int success = 1;
        for (int j = 0; j < returnSize; j++) {
            if (strcmp(sortedNames[j], expectedResults[i][j])) {
                success = 0;
                break;
            }
            //free(sortedNames[j]);
        }
        printf("%s\n", success == 1 ? "[+] Success !": "[-] Failed !");

        //free(sortedNames); // Free the array of names
    }
    return 0;
}