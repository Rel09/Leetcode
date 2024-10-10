#include <stack>
#include <vector>
#include <iomanip>
#include <iostream>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        
        int width = 0;
        std::stack<int> stack;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (stack.empty() || nums[stack.top()] < nums[i]) {
                stack.push(i);
            }
        }

        for (int i = 0; i < nums.size();) {

            if (!stack.size()) {
                return width;
            }

            if (stack.size() && nums[stack.top()] >= nums[i]) {
                width = std::max(width, stack.top() - i);
                stack.pop();
            }

            else {
                i++;
            }
        }
        return width;
    }
};

// Testing
int main() {

    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 3},
        {{1}, 0},
        {{5, 3, 5, 4, 4}, 3},
        {{7, 8, 7, 8, 9}, 4},
        {{11, 11, 22, 33, 33}, 4},
        {{101, 102, 102, 103, 103}, 4},
        {{0, 0, 1}, 2},
        {{42}, 0},
        {{100, 100, 999}, 2}
    };

    Solution solution;
    for (auto& test : tests) {
        int result = solution.maxWidthRamp(test.first);

        std::cout << "____________________________________________" << std::endl;
        std::cout << "Test case >> { ";
        for (const auto& num : test.first) {
            std::cout << num << " ";
        }
        std::cout << "} " << std::endl;
        std::cout << "Expected: " << test.second << " - Result: " << result << std::endl;
        std::cout << ((result == test.second) ? "[+] Passed!" : "[-] Failed!") << std::endl;

    }

    return 0;
}