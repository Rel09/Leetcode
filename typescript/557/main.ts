function reverseWords(s: string): string {
    let list: string[] = s.split(' ');

    for (let i = 0; i < list.length; i++) {
        list[i] = list[i].split('').reverse().join('');
    }

    return list.join(' ');
};





// Testing
const testCases = [
    { str: "Let's take LeetCode contest",   expectedStr: "s'teL ekat edoCteeL tsetnoc" },
    { str: "AbCdEFG",                       expectedStr: "GFEdCbA" },
    { str: "Pomme",                         expectedStr: "emmoP" },
    { str: "Mr Ding",                       expectedStr: "rM gniD" },
    { str: "",                              expectedStr: "" },
    { str: "hey",                           expectedStr: "yeh" },
];


testCases.forEach(({ str, expectedStr }, index) => {
    let result: String = reverseWords(str);
    if (result == expectedStr) {
        console.log(`Testcase [${index}] >> [+] Success !`)
    }
    else {
        console.log(`Testcase [${index}] >> [+] Failed !`)
    }

});