#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:

    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int maxDefense = 0;
        int weakCharacters = 0;

        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = std::max(maxDefense, properties[i][1]);
        }
        return weakCharacters;
    }

};

// Testing
int main() {
    
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        { {{5,5},{6,3},{3,6}},          0 },
        { {{2,2},{3,3}},                1 },
        { {{1,5},{10,4},{4,3}},         1 },
        { {{7,7},{1,1},{5,5}},          2 },
        { {{1,1},{2,1},{2,2},{1,2}},    1 },
        { {{10,2},{5,6},{8,4},{5,3}},   1 },
        { {{10,10},{10,1},{1,1},{2,2}}, 2 }
    };

    Solution solution;
    for (auto& test : tests) {
        std::vector<std::vector<int>>& properties = test.first;
        int expected = test.second;
        int output = solution.numberOfWeakCharacters(properties);
        
        std::cout << "______\ntest >>: ";
        for (const auto& p : properties) {
            std::cout << "[" << p[0] << "," << p[1] << "] ";
        }

        std::cout << "\n" << (expected == output ? "[+] Success !" : "[-] Failed !") << std::endl;
    }


    return 0;
}