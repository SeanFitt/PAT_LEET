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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> re;
        if(root==nullptr)
        return re;
        int counter=0;//每层的遍历个数，达到该层所对应的最后值则放入结果队列
        while(!q.empty())
        {
            vector<int> tmp;
            int l_len=q.size();
            for(int i=0;i<l_len;i++)
            {
                TreeNode* now=q.front();
                q.pop();
                tmp.push_back(now->val);
                if(now->left)
                q.push(now->left);
                if(now->right)
                q.push(now->right);
            }
            long int sum=0;
            for(int i=0;i<tmp.size();i++)
            {
                sum+=tmp[i];
            }
            re.push_back((double)sum/(double)tmp.size());
            tmp.clear();
        }
    return re;
    }
};