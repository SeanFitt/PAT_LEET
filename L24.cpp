#include<stdlib.h>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*依然是熟悉的转化为顺序结构做*/
ListNode* swapPairs(ListNode* head) 
{
    /*根据题目所给最大100个节点分配内存*/
    ListNode** L=(ListNode**)malloc(sizeof(ListNode*)*101);
    ListNode* now=head;
    int len=0;
    while(now!=nullptr)
    {
        L[len++]=now;
        now=now->next;
    }
    //如果链表长度不足1，不要操作，直接返回
    if(len<=1)
    return head;
    int pair=len/2;
    int index_1=0,index_2=0;
    //剩下的一个特殊处理
    bool one_left=len%2;
    //按2k,2k+1这样一对对处理
    for(int i=0;i<pair;i++)
    {
        index_2=i*2+1;
        L[index_1]->next=L[index_2];
        index_1=i*2;
        L[index_2]->next=L[index_1];       
    }
    if(one_left&&len!=1)
    {
        L[index_1]->next=L[index_2+1];
    }   
    if(!one_left)
    {
        L[index_1]->next=nullptr;
    }
    //返回新的头节点
    return L[1];
}
int main()
{
    ListNode* head=new ListNode(1);
    ListNode* now=head;
    for(int i=1;i<5;i++)
    {
        ListNode* n_Node=new ListNode(i+1);
        now->next=n_Node;
        now=n_Node;
    }
    ListNode* new_head=swapPairs(head);
    int bk=0;
    return 0;
}