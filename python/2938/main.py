class Solution(object):
    def minimumSteps(self, s):
        W = 0
        B = 0

        for c in s:
            if c == '0':
                W += B
            else:
                B += 1
        
        return W

# Testing
if __name__ == "__main__":
    test_cases = [
        ("010110", 4),
        ("000000", 0),
        ("111111", 0),
        ("101010", 6),
        ("000111", 0),
        ("100000", 5),
        ("000001", 0),
        ("100101", 4),
        ("00001111", 0),
        ("110100110", 13),
        ("1", 0),
        ("", 0),
        ("01010101010101010101", 45)
    ]

    solution = Solution()
    for i, (string, expectedResult) in enumerate(test_cases):
        answer = solution.minimumSteps(string);
        result = answer == expectedResult

        if result == True:
            msg = '[+] Success'
        else:
            msg = f'[-] Failed -----> {answer} VS {expectedResult}'

        print(f"Test case {i:<2} >>     [ {string:<20} ] -> {msg} !")
