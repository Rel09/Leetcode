#include <vector>       // Testing
#include <iomanip>      // Formating
#include <iostream>     // std::

class Solution {
public:
    int minSwaps(std::string s) {
        int open = 0;
        for (auto c : s) {
        
            if (c == '[') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                }
            }
        }

        return (open + 1) / 2;
    }
};


int main() {

    // Testing
    std::vector<std::pair<std::string, int>> tests = {
        {"", 0},
        {"][][", 1},
        {"]]][[[", 2},
        {"[]", 0},
    };

    Solution solution;
    for (const auto& test : tests) {
        const std::string& s = test.first;
        const int expected = test.second;
        const int result = solution.minSwaps(s);
        std::cout << std::left << "Test case >> " << std::setw(20) << s << " << Expected: " << expected << ", Result: " << result << " " << ((result == expected) ? "[+] Passed!" : "[-] Failed!") << std::endl;
    }

    return 0;
}