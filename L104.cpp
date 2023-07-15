#include<stdlib.h>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};    
};
bool getSame(ListNode* l,ListNode** ll,int len)
{
    for(int i=0;i<len;i++)
    {
        if(ll[i]==l)
        return true;
    }
    return false;
}
ListNode *detectCycle(ListNode *head) {
    ListNode** visited=(ListNode**)malloc(sizeof(ListNode*)*10001);
    int len=0;
    ListNode* now=head;
    while(now!=nullptr)
    {
        if(getSame(now,visited,len))
        return now;
        visited[len++]=now;
        now=now->next;
    }
    return nullptr;
}

int main()
{
    ListNode* l=new ListNode(1);
    ListNode* re = detectCycle(l);
    return 0;
}
