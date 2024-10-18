#include <vector>
#include <iomanip>
#include <iostream>
#include <map>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::map<int, bool> Map;
        int count = 0;

        for (auto& num: nums) {
            if (Map.find(num) == Map.end()) {
                Map[num] = true;
                count++;
            }
        }

        int index = 0;
        for (auto i : Map) {
            nums[index++] = i.first;
        }

        return count;
    }
};

// Testing
int main() {

    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1,2,3,4}, 4},
        {{1,2,3,4,5,6,7}, 7},
        {{1,2,3,4,4,4,4}, 4},
        {{1,2,3,4,5,6,7}, 7},
        {{1,2,3,4,1,2,3,4, 5}, 5},
    };

    Solution solution;
    for (auto& test : tests) {
        int result = solution.removeDuplicates(test.first);

        std::cout << "____________________________________________" << std::endl;

        std::cout << "Test case >> { ";
        for (const auto& i : test.first) {
            std::cout << i << ", ";
        }
        std::cout << " } " << std::endl;;

        std::cout << "Expected: " << test.second << " - Result: " << result << std::endl;
        std::cout << ((result == test.second) ? "[+] Passed!" : "[-] Failed!") << std::endl;

    }

    return 0;
}