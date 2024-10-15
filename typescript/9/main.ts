function isPalindrome(x: number): boolean {
    return x.toString() === x.toString().split('').reverse().join('')
};

// Testing
const testCases = [
    { nums: 2, expected: true },
    { nums: 54, expected: false },
    { nums: 919, expected: true },
    { nums: 111, expected: true },
    { nums: 2, expected: true },
    { nums: -999, expected: false },
];

testCases.forEach(({ nums, expected }, index) => {
    let result = isPalindrome(nums)
    if (result == expected) {
        console.log(`Testcase [${index}] >> [+] Success !`)
    }
    else {
        console.log(`Testcase [${index}] >> [+] Failed !`)
    }

});