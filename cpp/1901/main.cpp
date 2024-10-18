#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        std::vector<int> ret;

        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[i].size(); j++) {
                int result = 0;

                // Top
                if (i == 0 || mat[i - 1][j] < mat[i][j]) {
                    result++;
                }
                else { continue; }

                // Bottom
                if (i == mat.size() - 1 || mat[i + 1][j] < mat[i][j]) {
                    result++;
                }
                else { continue; }

                // Left
                if (j == 0 || mat[i][j - 1] < mat[i][j]) {
                    result++;
                }
                else { continue; }

                // Right
                if (j == mat[i].size() - 1 || mat[i][j + 1] < mat[i][j]) {
                    result++;
                }
                else { continue; }

                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
        }

        return ret;
    }

};

// Testing

void checkTestResult(const std::vector<int>& expected, const std::vector<int>& result, int testNumber) {
    if (expected == result) {
        std::cout << "[+] Test " << testNumber << " Passed !\n";
    }
    else {
        std::cout << "[-] Test " << testNumber << " Failed ! Expected: [" << expected[0] << ", " << expected[1] << "] Returned: ["  << result[0] << ", " << result[1] << "]\n";
    }
}

int main() {
    Solution sol;

   // Simple 3x3 matrix with a peak
    {
        std::vector<std::vector<int>> mat = {
            { 1, 2, 3 },
            { 6, 5, 4 },
            { 7, 8, 9 }
        };
        std::vector<int> expected = {2, 2};
        std::vector<int> peak = sol.findPeakGrid(mat);
        checkTestResult(expected, peak, 1);
    }

    // Single row
    {
        std::vector<std::vector<int>> mat = {
            { 1, 3, 2 }
        };
        std::vector<int> expected = {0, 1};
        std::vector<int> peak = sol.findPeakGrid(mat);
        checkTestResult(expected, peak, 2);
    }

    // Single column
    {
        std::vector<std::vector<int>> mat = {
            { 1 },
            { 3 },
            { 2 }
        };
        std::vector<int> expected = {1, 0};
        std::vector<int> peak = sol.findPeakGrid(mat);
        checkTestResult(expected, peak, 3);
    }

    // Larger matrix with multiple peaks
    {
        std::vector<std::vector<int>> mat = {
            { 10, 20, 15 },
            { 21, 30, 14 },
            { 7, 16, 32 }
        };
        std::vector<int> expected = {1, 1};
        std::vector<int> peak = sol.findPeakGrid(mat);
        checkTestResult(expected, peak, 4);
    }

    // 1x1 matrix
    {
        std::vector<std::vector<int>> mat = {
            { 42 }
        };
        std::vector<int> expected = {0, 0};
        std::vector<int> peak = sol.findPeakGrid(mat);
        checkTestResult(expected, peak, 5);
    }


    return 0;
}