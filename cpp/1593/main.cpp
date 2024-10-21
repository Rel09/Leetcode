#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int maxUniqueSplit(std::string s) {
        return backtrack(s, 0);
    }

private:
    std::unordered_set<std::string> str;

    int backtrack(const std::string& s, size_t start) {
        if (start == s.size()) {
            return 0;
        }

        std::string currentSubstring;
        int maxSplit = 0;
        for (size_t i = start; i < s.size(); ++i) {
            currentSubstring += s[i];

            if (str.find(currentSubstring) == str.end()) {
                str.insert(currentSubstring);
                
                int splitCount = 1 + backtrack(s, i + 1);
                
                maxSplit = std::max(maxSplit, splitCount);
                str.erase(currentSubstring);
            }
        }

        return maxSplit;
    }
};

// Testing
int main() {
    Solution solution;

    std::vector<std::pair<std::string, int>> tests = {
        {"ababccc",         5},
        {"aba",             2},
        {"aa",              1},
        {"abc",             3},
        {"aaaa",            2},
        {"abcdabcd",        6},
        {"xyzxyzxyz",       6},
        {"aab",             2},
        {"aabbcc",          4},
        {"",                0},
        {"pqrpq",           4},
        {"abcdefgh",        8},
        {"abcabcabc",       6},
        {"wwwzfvedwfvhsww", 11}
    };


    for (const auto& test : tests) {
        int result = solution.maxUniqueSplit(test.first);
        std::cout << "_____\nTestcase >> [ " << test.first << " ] \n" << (result == test.second ? "[+] Success !" : "[-] Failed !" ) << std::endl;
    }
    return 0;
}