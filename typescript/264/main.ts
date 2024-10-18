function nthUglyNumber(n: number): number {
    let uglyNumbers: number[] = new Array(n);
    uglyNumbers[0] = 1;
    
    let i2 = 0, i3 = 0, i5 = 0;
    let nextMultipleOf2 = 2;
    let nextMultipleOf3 = 3;
    let nextMultipleOf5 = 5;
    
    for (let i = 1; i < n; i++) {
        let nextUglyNumber = Math.min(nextMultipleOf2, nextMultipleOf3, nextMultipleOf5);
        uglyNumbers[i] = nextUglyNumber;
        
        if (nextUglyNumber === nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUglyNumber === nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUglyNumber === nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }
    
    return uglyNumbers[n - 1];
}

// Testing
const testCases = [
    { nums: 10,          expectedNum: 12 },
    { nums: 34,          expectedNum: 100 },
    { nums: 56,          expectedNum: 320 },
    { nums: 1,           expectedNum: 1 },
    { nums: 564,         expectedNum: 1769472 },
    { nums: 6541,        expectedNum: 1144409179687500 },
    { nums: 1234,        expectedNum: 210937500 }
];

testCases.forEach(({ nums, expectedNum }, index) => {
    let result: number = nthUglyNumber(nums);
    console.log(`Testcase [${index}] >> ${result == expectedNum ? "[+] Success !" : "[+] Failed"}`)
});