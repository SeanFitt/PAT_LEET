#include<queue>
using namespace std;
class MyStack {
public:
    //反向数据
    queue<int> q1;
    //临时队列
    queue<int> q2;
    int len=0;
    MyStack() {

    }
    //正常push
    void push(int x) {
        q1.push(x);
        len++;
    }
    //前n-1个先弹出，那么最后一个就是栈顶辣🥵
    int pop() {
        for(int i=0;i<len-1;i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int re=q1.front();
        q1.pop();
        len-=1;
        for(int i=0;i<len;i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return re;
    }
    
    //不用弹出最后一个了，真省事捏😋
    int top() {
        for(int i=0;i<len-1;i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int re=q1.front();
        q2.push(q1.front());
        q1.pop();
        for(int i=0;i<len;i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return re;
    }
    
    bool empty() {
        return len==0;
    }
};
