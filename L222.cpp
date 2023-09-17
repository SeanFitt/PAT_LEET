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
    int countNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        int left_counter=0,right_counter=0;
        while(left)
        {
            left=left->left;
            left_counter++;
        }
        while(right)
        {
            right=right->right;
            right_counter++;
        }
        if(left_counter==right_counter)
        return (int)pow(2,left_counter)-1;
        left_counter=countNodes(root->left);
        right_counter=countNodes(root->right);
        return left_counter+right_counter;
    }
};