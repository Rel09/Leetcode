class ListNode {
    val: number;
    next: ListNode | null;

    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {

    const head: ListNode = new ListNode(0);
    let currentNode: ListNode = head;
    
    let carry: number = 0; 

    while (l1 || l2 || carry) {
        const val1: number = l1 ? l1.val : 0;
        const val2: number = l2 ? l2.val : 0;
    
        const sum: number = val1 + val2 + carry;
        carry = Math.floor(sum / 10);
        currentNode.next = new ListNode(sum % 10);
        currentNode = currentNode.next;

        if (l1) { l1 = l1.next; }
        if (l2) { l2 = l2.next; }
    }

    return head.next;
}


// Testing
function createLinkedList(arr: number[]): ListNode | null {
    let head: ListNode = new ListNode(0);
    let current: ListNode = head;
    for (let num of arr) {
        current.next = new ListNode(num);
        current = current.next;
    }
    return head.next;
}

function linkedListToArray(head: ListNode | null): number[] {
    let result: number[] = [];
    while (head) {
        result.push(head.val);
        head = head.next;
    }
    return result;
}

const tests = [
    { l1: [2, 4, 3],                        l2: [5, 6, 4],     expected: [7, 0, 8] },
    { l1: [0],                              l2: [0],           expected: [0] },
    { l1: [9, 9, 9, 9, 9],                  l2: [1],           expected: [0, 0, 0, 0, 0, 1] },
    { l1: [2, 4, 3],                        l2: [5, 6],        expected: [7, 0, 4] },
    { l1: [1],                              l2: [9, 9, 9],     expected: [0, 0, 0, 1] },
    { l1: [0],                              l2: [9, 1],        expected: [9, 1] },
    { l1: [9, 9],                           l2: [1],           expected: [0, 0, 1] },
    { l1: [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], l2: [5, 6, 4], expected: [6, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1] }
];

tests.forEach(({ l1, l2, expected }, index) => {
    const resultArray = linkedListToArray(addTwoNumbers(createLinkedList(l1), createLinkedList(l2)));
    console.log(`[Test Case ${index + 1}] >>`, JSON.stringify(resultArray) === JSON.stringify(expected) ? "Passed" : "Failed");
});