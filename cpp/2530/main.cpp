#include <queue>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>

class Solution {
public:

    long long maxKelements(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        
        std::priority_queue<int> q;
        for (size_t i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        long long result = 0;
        int operationCount = 0;
        while (!q.empty() && operationCount < k) {
            int top = q.top();
            q.pop();
            result += top;

            q.push(static_cast<int>(ceil(static_cast<double>(top) / 3)));
            operationCount++;
        }

        return result;
    }


};

// Testing
int main() {

    std::vector<std::tuple<std::vector<int>, int, long long>> tests = {
        {{10, 20, 7},   2,      30},
        {{5, 5, 5, 5},  3,      15},
        {{1, 2, 3},     1,      3},
        {{10, 20, 30},  1,      30},
        {{1, 100, 1},   3,      146},
        {{0, 0, 0},     2,      0},
    };

    Solution solution;
    for (auto& test : tests) {
        auto& [nums, k, expected] = test;
        long long result = solution.maxKelements(nums, k);
        
        std::cout << "Input: {";
        for (const auto& num : nums) {
            std::cout << num << " ";
        }

        std::cout << "}, k: " << k << " => Expected: " << expected << ", Got: " << result;
        std::cout << ((result == expected) ? "\n[+] Passed!" : "\n[-] Failed!") << std::endl;
    }
    

    return 0;
}