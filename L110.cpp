#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

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
    int getDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if (abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};