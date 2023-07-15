#include<stdlib.h>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
        int len=0;
        ListNode** L=(ListNode**)malloc(sizeof(ListNode*)*31);
        ListNode* now=head;
        while(now!=nullptr)
        {
            L[len++]=now;
            now=now->next;
        }
        int delete_index=len-n;
        //如果是头节点，将后一个节点置为头，该节点删除。
        if(delete_index==0)
        {
            //对于长度为1的链表特殊处理，返回一个空的链表
            if(len==1)
            return now;
            delete(L[0]);
            return L[1];
        }
        //如果不是头节点，将该节点删除，并将其前后俩节点拼接。
        else
        {
            L[delete_index-1]->next=L[delete_index]->next;
            delete(L[delete_index]);
        }
        return head;    
}

int main()
{
    ListNode* head=new ListNode(1);
    ListNode* now=head;
    for(int i=1;i<1;i++)
    {
        ListNode* n_Node=new ListNode(i+1);
        now->next=n_Node;
        now=n_Node;
    }
    ListNode* new_head=removeNthFromEnd(head,1);
    int bk=0;
    return 0;
}