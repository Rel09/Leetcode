#include <vector>
#include <iostream>

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int len = (1 << n) - 1; 
        int mid = len / 2 + 1;  

        if (k == mid) {
            return '1';
        }

        if (k < mid) {
            return findKthBit(n - 1, k);
        }

        char bit = findKthBit(n - 1, len - k + 1);
        return bit == '0' ? '1' : '0';
    }
};

// Testing
int main() {
    Solution solution;

        std::vector<std::vector<int>> tests = {
        {3, 1, '0'},
        {3, 5, '0'},
        {4, 8, '1'},
        {4, 12, '0'},
        {2, 2, '1'},
        {5, 10, '1'},
        {5, 16, '1'},
        {6, 32, '1'},
        {6, 1, '0'},
        {6, 15, '1'},
        {7, 50, '1'}
    };

    for (const auto& testCase : tests) {
        int n = testCase[0];
        int k = testCase[1];
        char expected = testCase[2];
        char result = solution.findKthBit(n, k);

        std::cout << "____\nTestcase >> [n = " << n << "]  [k = " << k << "] " << (result == expected ? "\n[+] Success !" : "[-] Failed !") << std::endl;
    }

    return 0;
}