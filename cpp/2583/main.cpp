#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<long long> levelSums;
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                levelSum += currentNode->val;

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            levelSums.push_back(levelSum);
        }

        if (k > levelSums.size()) return -1;
        std::sort(levelSums.begin(), levelSums.end(), std::greater<long long>());
        return levelSums[k - 1];
    }
};

// Testing
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Standard binary tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    std::cout << "Test Case 1 >>    k=2: " << (solution.kthLargestLevelSum(root1, 2) == 5 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root1);

    // Single node tree
    TreeNode* root2 = new TreeNode(10);
    std::cout << "Test Case 2 >>    k=1: " << (solution.kthLargestLevelSum(root2, 1) == 10 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root2);

    // Larger tree with more levels
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    root3->left->left->left = new TreeNode(8);
    root3->left->left->right = new TreeNode(9);
    std::cout << "Test Case 3 >>    k=1: " << (solution.kthLargestLevelSum(root3, 1) == 22 ? "[+] Success !" : "[-] Failed !") << std::endl;
    std::cout << "Test Case 4 >>    k=3: " << (solution.kthLargestLevelSum(root3, 3) == 5 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root3);

    // Tree with fewer levels than k
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    std::cout << "Test Case 5 >>    k=3: " << (solution.kthLargestLevelSum(root4, 3) == -1 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root4);

    // Tree with negative values
    TreeNode* root5 = new TreeNode(-1);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(-3);
    root5->left->left = new TreeNode(-4);
    root5->left->right = new TreeNode(-5);
    root5->right->left = new TreeNode(-6);
    root5->right->right = new TreeNode(-7);
    std::cout << "Test Case 6 >>    k=2: " << (solution.kthLargestLevelSum(root5, 2) == -5 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root5);

    // Tree with one child at each level
    TreeNode* root6 = new TreeNode(5);
    root6->right = new TreeNode(10);
    root6->right->right = new TreeNode(20);
    root6->right->right->right = new TreeNode(40);
    std::cout << "Test Case 7 >>    k=1: " << (solution.kthLargestLevelSum(root6, 1) == 40 ? "[+] Success !" : "[-] Failed !") << std::endl;
    std::cout << "Test Case 8 >>    k=3: " << (solution.kthLargestLevelSum(root6, 3) == 10 ? "[+] Success !" : "[-] Failed !") << std::endl;
    freeTree(root6);

    return 0;
}