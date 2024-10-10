#include <vector>
#include <iomanip>
#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        int num = 0;
        for (auto i : nums) {
            num ^= i;
        }
        return num;
    }
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (const auto& i : vec) {
        os << i << " ";
    }
    return os;
}

// Testing
int main() {

    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 4},
        {{1}, 1},
        {{5, 3, 5, 4, 4}, 3},
        {{7, 8, 7, 8, 9}, 9},
        {{11, 11, 22, 33, 33}, 22},
        {{101, 102, 102, 103, 103}, 101},
        {{0, 0, 1}, 1},
        {{42}, 42},
        {{100, 100, 999}, 999}
    };

    Solution solution;
    for (auto& test : tests) {
        int result = solution.singleNumber(test.first);

        std::cout << "____________________________________________" << std::endl;
        std::cout << "Test case >> " << test.first << std::endl;
        std::cout << "Expected: " << test.second << " - Result: " << result << std::endl;
        std::cout << ((result == test.second) ? "[+] Passed!" : "[-] Failed!") << std::endl;

    }

    return 0;
}