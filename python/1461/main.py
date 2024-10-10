class Solution(object):

    def hasAllCodes(self, s, k):
        if len(s) < k:
            return False
        setArray = set()
        for i in range(len(s) - k + 1):
            binaryStr = s[i:i+k]
            setArray.add(binaryStr)
        return len(setArray) ==  (2 ** k)

# Testing
if __name__ == "__main__":

    test_cases = [
        ("00110110", 2, True),
        ("0110", 1, True),
        ("0110", 2, False),
        ("0000000001011100", 4, False),
        ("1111111111", 2, False),
        ("101010", 3, False),
        ("1101010110110001", 3, False),
        ("000111", 2, False),
        ("", 1, False),
        ("00000", 5, False),
    ]

    solution = Solution()

    for i, (s, k, expected) in enumerate(test_cases):
        result = solution.hasAllCodes(s, k)
        print(f"Test case >> [{i}] | [ {s:<20} ] [ k = {k} ] | Result: {'Success' if expected == result else 'Failed'}")