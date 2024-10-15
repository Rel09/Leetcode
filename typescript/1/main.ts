function twoSum(nums: number[], target: number): number[] {
    const map: { [key: number]: number } = {};

    for (let i = 0; i < nums.length; i++) {
        const val = nums[i];
        const t = target - val;
        if (map[t] != null) {
            return [map[t], i];
        }
        map[val] = i;
    }

    return [];
}

// Testing
function arraysIsEqual(arr1: number[], arr2: number[]): boolean {
    if (arr1.length !== arr2.length) {
        return false;
    }
    for (let i = 0; i < arr1.length; i++) {
        if (arr1[i] !== arr2[i]) {
            return false;
        }
    }
    return true;
}

const testCases = [
    { nums: [2, 7, 11, 15],     target: 9,      expected: [0, 1] },
    { nums: [3, 2, 4],          target: 6,      expected: [1, 2] },
    { nums: [3, 3],             target: 6,      expected: [0, 1] },
    { nums: [1, 2, 3, 4],       target: 5,      expected: [1, 2] },
    { nums: [1, 2, 3],          target: 7,      expected: [] },
];

testCases.forEach(({ nums, target, expected }, index) => {
    let result = twoSum(nums, target)
    if (arraysIsEqual(result, expected)) {
        console.log(`Testcase [${index}] >> [+] Success !`)
    }
    else {
        console.log(`Testcase [${index}] >> [+] Failed !`)
    }

});