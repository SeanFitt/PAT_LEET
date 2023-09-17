#include<vector>
#include<string>
#include<string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int visit(TreeNode* now,bool is_left,int &re)
    {
        if(is_left&&now->left==nullptr&&now->right==nullptr)
            return now->val;
        if(now->left)
        {
            re+=visit(now->left,true,re);
        }
        if(now->right)
        {
            re+=visit(now->right,false,re);
        }
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int re=0;
        if(root==nullptr)
        return re;
        visit(root,false,re);
        return re;
    }
};