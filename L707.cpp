#include<stdio.h>
class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    int len;
    ListNode* head;
    
public:
    MyLinkedList() {
        len=0;
        head=nullptr;
    }
    
    int get(int index) {
        if(index<0||index>=len)
            return -1;
        else{
            ListNode* now=head;
            for(int i=0;i<index;i++)
                now=now->next;
            return now->val;
        }
    }
    
    void addAtHead(int val) {
        ListNode* now=new ListNode(val);
        if(head==nullptr)
        {
            head=now;
        }
        else{
            now->next=head;
            head=now; 
        }
        len++;             
    }
    
    void addAtTail(int val) {
        if(len==0)
        {
            addAtHead(val);
            return ;
        }
        ListNode* now=new ListNode(val);
        ListNode* index=head;
        for(int i=0;i<len-1;i++)
        {
            index=index->next;
        }
        len++;
        index->next=now;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>len)
        return;
        ListNode* L=new ListNode(val);
        ListNode* now=head;
        ListNode* pre=nullptr;
        if(index==0)
        {
            addAtHead(val);
            return ;
        }
        else if(index==len)
        {
            addAtTail(val);
            return ;
        }
        else{
            for(int i=0;i<index;i++){
                pre=now;
                now=now->next;
            }
            pre->next=L;
            L->next=now;
        }   
        len++;   
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>len-1)
        return;
        ListNode* now=head;
        ListNode* pre=nullptr;
        for(int i=0;i<index;i++)
        {
            pre=now;
            now=now->next;
        }
        //头节点
        if(index==0)
        {
            head=head->next;
            delete now;
        }
        //非头、尾节点
        else if(index!=len-1)
        {
            pre->next=now->next;
            delete(now);
        }
        //尾节点
        else{
            pre->next=nullptr;
            delete(now);
        }
        len--;
    }
    int getLen(){
        return len;
    }
};
void result_helper(MyLinkedList* L)
{
    int len=L->getLen();
    for(int i=0;i<len-1;i++)
    {
        printf("%d ",L->get(i));
    }
    printf("\n");
}

int main()
{
    MyLinkedList* l=new MyLinkedList();
    // l->addAtHead(1);
    // l->addAtTail(3);
    // l->addAtIndex(1,2);
    // l->get(1);
    // l->deleteAtIndex(1);
    // l->get(1);

    // l->addAtHead(7);
    // l->addAtHead(2);
    // l->addAtHead(1);
    // l->addAtIndex(3,0);
    // l->deleteAtIndex(2);
    // l->addAtHead(6);
    // l->addAtTail(4);
    // l->get(4);
    // l->addAtHead(4);
    // l->addAtIndex(5,0);
    // l->addAtHead(6);

    l->addAtTail(1);
    l->addAtTail(3);
    l->get(0);

    return 0;
}