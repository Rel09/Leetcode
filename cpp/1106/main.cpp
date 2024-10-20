#include <vector>
#include <iostream>

struct Parenthesis {
    int first;
    int second;
};

class Solution {
public:
    bool parseBoolExpr(std::string expression) {
        if (expression == "t")  {
            return true;
        }
        if (expression == "f") {
            return false;
        }
        
        Parenthesis T = getPair(expression);
        while (T.first != 0) {
            char symbol = expression[T.first - 1];
            std::string substr = expression.substr((T.first + 1), T.second - (T.first + 1));

            std::vector<char> values = getValues(substr);
            bool result = false;

            if (symbol == '!') {
                result = !parseBoolExpr(substr);
            }

            else if (symbol == '&') {
                result = evaluateAND(values);
            }
            
            else if (symbol == '|') {
                result = evaluateOR(values);
            }

            expression.replace(T.first - 1, T.second - T.first + 2, result ? "t" : "f");
            T = getPair(expression);
        }

        return expression == "t";
    }

private:
    Parenthesis         getPair(const std::string& expression) const {
        Parenthesis T = {0, 0};

        for (size_t i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (c == '(') {
                T.first = i;
                T.second = 0;
            }

            if (c == ')' && T.first != 0) {
                T.second = i;
                return T;
            }
        }

        return {0, 0};
    }

    std::vector<char>   getValues(const std::string& expression) const {
        std::vector<char> T;

        for (const char& c : expression) {
            if (c == 't' || c == 'f') {
                T.push_back(c);
            }
        }
        return T;
    }

    bool                evaluateAND(const std::vector<char>& values) const {
        for (const char& c : values) {
            if (c == 'f') {
                return false;
            }
        }
        return true;
    }

    bool                evaluateOR(const std::vector<char>& values) const {
        for (const char& c : values) {
            if (c == 't') {
                return true;
            }
        }
        return false;
    }
};


// Testing
int main() {
    Solution solution;

    std::vector<std::pair<std::string, bool>> tests = {
        {"!(f)",                true},
        {"|(&(t,f),!(f))",      true},
        {"&(!(t),|(f,t))",      false},
        {"|(t,f,t)",            true},
        {"&(!(f),t)",           true},
        {"&(t,t,t)",            true},
        {"|(!(t),&(t,t))",      true},
        {"!(&(f,t))",           true},
        {"|(f,f)",              false},
        {"&(!(f),!(t))",        false},
    };


    for (const auto& testCase : tests) {
        const std::string& expression = testCase.first;
        bool expected = testCase.second;
        bool result = solution.parseBoolExpr(expression);

        std::cout << "____\nTestcase: [ " << expression << " ]" << (result == expected ? "\n[+] Success!" : "\n[-] Failed!") << std::endl;
    }

    return 0;
}