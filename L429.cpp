#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> re;
        if(root==nullptr)
        return re;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int> tmp_re;
            for(int i=0;i<len;i++)
            {
                Node* now=q.front();
                q.pop();
                tmp_re.push_back(now->val);
                if(!now->children.empty())
                {
                    int len_child=now->children.size();
                    for(int j=0;j<len_child;j++)
                    {
                        q.push(now->children[j]);
                    }
                }
            }
            re.push_back(tmp_re);
        }
    return re;
    }
};