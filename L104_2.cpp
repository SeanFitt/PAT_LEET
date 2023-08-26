#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
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
    int maxDepth(TreeNode* root) {
        int re=0;
        if(root==nullptr)
        return re;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            re++;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* now=q.front();
                q.pop();
                if(now->left)
                q.push(now->left);
                if(now->right)
                q.push(now->right);
            }
        }
        return re;
    }
};