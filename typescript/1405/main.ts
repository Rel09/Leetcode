function longestDiverseString(a: number, b: number, c: number): string {
    let ret: string = "";

    let arr = [
        { char: 'a', count: a },
        { char: 'b', count: b },
        { char: 'c', count: c }
    ];
    
    while (true) {
        arr.sort((x, y) => y.count - x.count);
        
        let added = false;
        for (let i = 0; i < arr.length; i++) {

            if (ret.length >= 2 && ret[ret.length - 1] === arr[i].char && ret[ret.length - 2] === arr[i].char) {
                continue;
            }
            
            if (arr[i].count > 0) {
                ret += arr[i].char;
                arr[i].count--;
                added = true;
                break;
            }
        }
        
        if (!added) {
            break;
        }
    }
    
    return ret;
}

// Testing
const testCases = [
    { nums: [1,1,7],   expectedStr: "ccaccbcc" },
    { nums: [9,9,1],   expectedStr: "abbaabbaabbaabbaabc" },
    { nums: [0,1,0],   expectedStr: "b" },
    { nums: [1,2,3],   expectedStr: "ccbbca" },
    { nums: [5,0,5],   expectedStr: "accaaccaac" },
    { nums: [1,1,1],   expectedStr: "abc" },
    { nums: [1,2,3],   expectedStr: "ccbbca" }
];

testCases.forEach(({ nums, expectedStr }, index) => {

    let result: String = longestDiverseString(nums[0], nums[1], nums[2]);
    if (result == expectedStr) {
        console.log(`Testcase [${index}] >> [+] Success !`)
    }
    else {
        console.log(`Testcase [${index}] >> [+] Failed !`)
    }

});