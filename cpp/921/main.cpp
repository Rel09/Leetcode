#include <vector>
#include <iomanip>
#include <iostream>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        int open = 0;
        int closed = 0;

        for (const char&c : s) {
            if (c == '(') {
                open++;
            }
            else {
                open > 0 ? open-- : closed++;
            }
        }
        return open + closed;
    }

};

// Testing
int main() {

    std::vector<std::pair<std::string, int>> tests = {
        {"()", 0},
        {"((", 2},
        {"))", 2},
        {"())", 1},
        {"(()", 1},
        {"(()))", 1},
        {"", 0},
        {")(", 2},
        {"(((", 3},
        {"))))", 4}
    };

    Solution solution;
    for (auto& test : tests) {
        int result = solution.minAddToMakeValid(test.first);

        std::cout << "____________________________________________" << std::endl;
        std::cout << "Test case >> " << test.first << std::endl;
        std::cout << "Expected: " << test.second << " - Result: " << result << std::endl;
        std::cout << ((result == test.second) ? "[+] Passed!" : "[-] Failed!") << std::endl;

    }

    return 0;
}