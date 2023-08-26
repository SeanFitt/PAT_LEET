#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> re;
        if(root==nullptr)
        return re;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int> tmp;
            for(int i=0;i<len;i++)
            {
                TreeNode* now=q.front();
                q.pop();
                tmp.push_back(now->val);
                if(now->left)
                q.push(now->left);
                if(now->right)
                q.push(now->right);
            }
            auto max_pos=max_element(tmp.begin(),tmp.end());
            int max_value = *max_pos;
            re.push_back(max_value);
            tmp.clear();
        }
        return re;
    }
};

int main() {
    // 构造二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // 创建 Solution 对象并调用函数
    Solution solution;
    vector<int> largestValues = solution.largestValues(root);

    // 输出结果
    cout << "最大值：";
    for (int val : largestValues) {
        cout << val << " ";
    }
    cout << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}