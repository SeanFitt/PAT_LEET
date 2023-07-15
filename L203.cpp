#include<stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeElements(ListNode* head, int val) {
    ListNode* now=head;//当前节点
    ListNode* pre=nullptr;//前一个节点
    while(now!=nullptr){
        if(now->val==val){
            if(pre==nullptr){
                head=now->next;
                //保持良好的习惯，用完释放内存
                delete now;
                now=head;
            }
            else{
                pre->next=now->next;
                delete now;
                now=pre->next;
            }
        }
        else{
            pre=now;
            now=now->next;
        }        
    }
    return head;
}
int main()
{
    ListNode* head=new ListNode(1);
    ListNode* now=head;
    for(int i=2;i<6;i++){
        now->next=new ListNode(i);
        now=now->next;
    }
    now=head;
    while(now!=nullptr){
        printf("%d ",now->val);
        now=now->next;
    }
    printf("\n");
    now=removeElements(head,6);
    while(now!=nullptr){
        printf("%d ",now->val);
        now=now->next;
    }
    printf("\n");
    return 0;
}

