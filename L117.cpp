#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr)
        return root;
        q.push(root);
        Node* now;
        while(!q.empty())
        {
            int len=q.size();
            //vector<Node*> tmp;
            for(int i=0;i<len-1;i++)
            {
                now=q.front();
                q.pop();
                now->next=q.front();
                if(now->left)
                {
                    q.push(now->left);
                    q.push(now->right);
                }
            }
            now=q.front();
            now->next=NULL;
            if(now->left)
            {
                q.push(now->left);
                q.push(now->right);
            }
            q.pop();
        }
        return root;
    }
};

// 测试用例
int main() {
    // 构造完美二叉树
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // 创建 Solution 对象并调用函数
    Solution solution;
    Node* connectedTree = solution.connect(root);

    // 输出每个节点的 val 和 next 指针
    std::cout << "节点值和 next 指针：" << std::endl;
    std::queue<Node*> printQueue;
    printQueue.push(connectedTree);
    while (!printQueue.empty()) {
        Node* node = printQueue.front();
        printQueue.pop();
        std::cout << "节点值: " << node->val;
        if (node->next)
            std::cout << "，next 指针: " << node->next->val;
        std::cout << std::endl;
        if (node->left)
            printQueue.push(node->left);
        if (node->right)
            printQueue.push(node->right);
    }

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}