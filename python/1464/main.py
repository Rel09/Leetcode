class Solution(object):
    def maxProduct(self, nums):
        sortedReversedArr = sorted(nums, reverse=True)[:2]
        return (sortedReversedArr[0] - 1 ) * (sortedReversedArr[1] - 1)

# Testing
if __name__ == "__main__":

    test_cases = [
        ([3, 4, 5, 2], 12),
        ([1, 5, 4, 5], 16),
        ([3, 7], 12),
        ([10, 2, 5, 6], 45),
        ([1, 1, 1, 1], 0),
        ([9, 10, 8, 7], 72),
        ([1, 2], 0),
        ([100, 200], 19701),
        ([5, 4, 6, 7], 30),
        ([9, 9, 9], 64)
    ]

    solution = Solution()

    for i, (nums, expected) in enumerate(test_cases):
        result = solution.maxProduct(nums)
        print(f"Test case >> [{i}] |  {str(nums):<30}  | Expected: {str(expected):<7} | Result: {'Success' if expected == result else 'Failed'}")