#include<vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> re;
        queue<TreeNode*> pre;//暂存本层节点
        // queue<TreeNode*> now;//下一层节点
        if(root==nullptr)
        return re;
        pre.push(root);
        while(pre.size()!=0)
        {
            int len=pre.size();
            vector<int> l_data;//保存节点的value
            for(int i=0;i<len;i++)
            {
                TreeNode* tmp_Node=pre.front();
                l_data.push_back(tmp_Node->val);
                pre.pop();
                if(tmp_Node->left)
                pre.push(tmp_Node->left);
                if(tmp_Node->right)
                pre.push(tmp_Node->right);
            }
            re.push_back(l_data);    
        }
        reverse(re.begin(),re.end());
        return re;
    }
};