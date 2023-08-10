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
    void forward(TreeNode* now,vector<int>& re)
    {
        stack<TreeNode*> s;
        s.push(now);
        while(!s.empty())
        {
            TreeNode* tmp=s.top();
            re.push_back(tmp->val);
            s.pop();
            if(tmp->right!=nullptr)
            s.push(tmp->right);
            if(tmp->left!=nullptr)
            s.push(tmp->left);
            
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        forward(root,re);
        return re;
    }
};