#include <vector>       // Testing & Solution
#include <iomanip>      // Formating
#include <iostream>     // std::

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> results(n - 2, std::vector<int>(n - 2));

        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {

                int biggestValue = 0;
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        if (grid[x][y] > biggestValue) {
                            biggestValue = grid[x][y];
                        }
                    }
                }

                results[i][j] = biggestValue;
            }
        }

        return results;
    }
};


int main() {

    // Testing
    std::vector<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> tests = {
        { { {9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2} }, {{9, 9}, {8, 6}} },
        { { {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 2, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1} }, {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}} }
    };

    Solution solution;
    for (auto& test : tests) {
        std::vector<std::vector<int>>& grid = test.first;
        std::vector<std::vector<int>>& expected = test.second;
        std::vector<std::vector<int>> result = solution.largestLocal(grid);

        std::cout << "Test case >>\nInput: ";
        for (const auto& row : grid) {
            std::cout << "{ ";
            for (const int val : row) {
                std::cout << val << " ";
            }
            std::cout << "} ";
        }

        std::cout << "\nExpected: ";
        for (const auto& row : expected) {
            std::cout << "{ ";
            for (const int val : row) {
                std::cout << val << " ";
            }
            std::cout << "} ";
        }

        std::cout << "\nResult: ";
        for (const auto& row : result) {
            std::cout << "{ ";
            for (const int val : row) {
                std::cout << val << " ";
            }
            std::cout << "} ";
        }

        std::cout << ((result == expected) ? "\n[+] Passed!" : "\n[-] Failed!") << std::endl;
        std::cout << std::endl;
    }

    return 0;
}