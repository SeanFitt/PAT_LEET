#include<stack>
using namespace std;

class MyQueue {
public:
    //原始栈
    stack<int> s;
    //翻转栈（队列）
    stack<int> q;
    int len=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
        len++;
    }
    //翻转栈
    int pop() {
        for(int i=0;i<len;i++)
        {
            q.push(s.top());
            s.pop();
        }
        int re =q.top();
        q.pop();
        len--;
        for(int i=0;i<len;i++)
        {
            s.push(q.top());
            q.pop();
        }
        return re;
    }
    
    int peek() {
        for(int i=0;i<len;i++)
        {
            q.push(s.top());
            s.pop();
        }
        int re =q.top();
        for(int i=0;i<len;i++)
        {
            s.push(q.top());
            q.pop();
        }
        return re;
    }
    
    bool empty() {
        return len==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */