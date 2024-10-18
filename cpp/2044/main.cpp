#include <vector>
#include <iostream>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxOr = 0;
        int count = 0;
        
        for (int num : nums) {
            maxOr |= num;
        }
        
        backtrack(nums, 0, 0, maxOr, count);
        return count;
    }

private:
    void backtrack(const std::vector<int>& nums, size_t index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        backtrack(nums, index + 1, currentOr | nums[index], maxOr, count);
        backtrack(nums, index + 1, currentOr, maxOr, count);
    }
};

// Testing
int main() {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 3, 4}, 5},  
        {{3, 1, 5, 6}, 9},
        {{0, 1}, 2},
        {{1, 2, 3, 4, 5}, 17},
        {{0}, 2}
    };

    Solution solution;
    int i = 0;
    for (auto& test : tests)  {
        auto& arr = test.first;
        const auto& expected = test.second;

        int result = solution.countMaxOrSubsets(arr);
        std::cout << "Testcase " << i++ << " >> " <<((result == expected) ? "[+] Passed!" : "[-] Failed!") << std::endl;
    }
    

    return 0;
}