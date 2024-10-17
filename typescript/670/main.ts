function maximumSwap(num: number): number {
    let digits: number[] = num.toString().split('').map(Number);
    const strlen = digits.length;

    let index1:number = -1;
    let index2:number = -1;
    let maxDigit:number = -1;
    let maxIndex:number = -1;

     for (let i = strlen - 1; i >= 0; i--) {
        if (digits[i] > maxDigit) {
            maxDigit = digits[i];
            maxIndex = i;
        }
        else if (digits[i] < maxDigit) {
            index1 = maxIndex;
            index2 = i;
        }
    }

    if (index1 > -1) {
        const temp:number = digits[index1];
        digits[index1] = digits[index2];
        digits[index2] = temp;
        return parseInt(digits.join(''), 10);
    }

    return num;
};

// Testing
const testCases = [
    { nums: 67345,      expectedNum: 76345 },
    { nums: 31455,      expectedNum: 51453 },
    { nums: 123214,     expectedNum: 423211 },
    { nums: 12,         expectedNum: 21 },
    { nums: 21,         expectedNum: 21 },
    { nums: 1,          expectedNum: 1 },
    { nums: 191,        expectedNum: 911 }
];

testCases.forEach(({ nums, expectedNum }, index) => {
    let result: number = maximumSwap(nums);
    console.log(`Testcase [${index}] >> ${result == expectedNum ? "[+] Success !" : "[+] Failed"}`)
});