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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
        return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<TreeNode*> tmp;
            for(int i=0;i<len;i++)
            {
                TreeNode* now=q.front();
                q.pop();
                tmp.push_back(now);
            }
            for(int i=0;i<tmp.size()/2;i++)
            {
                int exchange_tmp=tmp[i]->val;
                tmp[i]->val=tmp[tmp.size()-1-i]->val;
                tmp[tmp.size()-1-i]->val=exchange_tmp;
            }
        }
        return root;
    }
};

int main() {
    // 创建一棵二叉树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // 创建解决方案对象
    Solution solution;

    // 翻转二叉树
    TreeNode* invertedRoot = solution.invertTree(root);

    // 打印翻转后的二叉树（层序遍历）
    queue<TreeNode*> q;
    q.push(invertedRoot);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;

    return 0;
}