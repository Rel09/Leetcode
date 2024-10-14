#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	getDigits(int n) {
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*itoa(int n) {
	char		*str;
	size_t		digits;
	long int	num;

	num = n;
	digits = getDigits(n);
	if (n < 0) {
		num *= -1;
		digits++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (digits + 1)))) {
		return (NULL);
    }
	*(str + digits) = 0;
	while (digits--) {
		*(str + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0) {
		*(str + 0) = '-';
    }
	return (str);
}

int maximumSwap(int num) {
    char *buf = itoa(num);

    int last[10];
    for (int i = 0; i < 10; i++) {
        last[i] = -1;
    }

    for (int i = 0; buf[i]; i++) {
        last[buf[i] - '0'] = i;
    }

    for (int i = 0; buf[i]; i++) {
        for (int d = 9; d > buf[i] - '0'; d--) {
            if (last[d] > i) {
                char temp = buf[i];
                buf[i] = buf[last[d]];
                buf[last[d]] = temp;
                return atoi(buf);
            }
        }
    }
    
    return num;
}

// Testing
int main() {

    int testCases[] =       {2736, 9973, 1234, 4321, 0, 9, 987654321, 1234, 1993};
    int expectedResults[] = {7236, 9973, 4231, 4321, 0, 9, 987654321, 4231, 9913};

    size_t numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (size_t i = 0; i < numTests; i++) {
        int result = maximumSwap(testCases[i]);
        printf(">> Test case [%d]: maximumSwap(%d) = %d; Expected = %d\n", (int)i + 1, testCases[i], result, expectedResults[i]);
        printf("%s\n", result == expectedResults[i] ? "[+] Success !" : "[-] Failed !" );
    }

    return 0;
}