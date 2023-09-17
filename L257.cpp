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
    string convert(vector<int> &re)
    {
        string res;
        for(int i=0;i<re.size();i++)
        {
            if(i!=0)
            res.append("->");
            res.append(to_string(re[i]));
        }
        return res;
    }
    void visit(TreeNode* now, vector<int> &re,vector<string> &res){
        if(now->left==nullptr&&now->right==nullptr)
        {
            string tmp_s=convert(re);
            res.push_back(tmp_s);
            return;
        }
        if(now->left)
        {
            re.push_back(now->left->val);
            visit(now->left,re,res);
            re.pop_back();
        }
        if(now->right)
        {
            re.push_back(now->right->val);
            visit(now->right,re,res);
            re.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==nullptr)
            return res;
        vector<int> memory;
        memory.push_back(root->val);
        visit(root,memory,res);
        return res;
    }
};