#include<vector>
#include<stack>
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
    //递归
    // void visit(TreeNode* now,vector<int>& re)
    // {
    //     if(now==NULL)
    //     return;
    //     visit(now->left,re);
    //     re.push_back(now->val);
    //     visit(now->right,re);
    // }
    //迭代
    void visit(TreeNode* root, vector<int>& re) {
    stack<TreeNode*> s;
    TreeNode* now = root;
    if (root == nullptr)
        return;
    s.push(root);
    now=root->left;
    while(!s.empty()|| now != nullptr) {
        while (now!= nullptr) {
            s.push(now);
            now=now->left;
        }
        now=s.top();
        re.push_back(now->val);
        s.pop();
        now=now->right; 
    }
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        visit(root,re);
        return re;
    }
};