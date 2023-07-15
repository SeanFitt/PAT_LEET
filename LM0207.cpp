#include<stdlib.h>
#include <math.h>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nowA=headA;
        ListNode* nowB=headB;
        bool flag;
        //统计A和B链表长度，用于后续对其查找公共节点
        int lenA=0,lenB=0;
        while(nowA!=nullptr)
        {
            lenA++;
            nowA=nowA->next;
        }
        while(nowB!=nullptr)
        {
            lenB++;
            nowB=nowB->next;
        }
        //计算长度差，从长链表的distance开始查找
        int distance=abs(lenA-lenB);
        //重置节点指针
        nowA=headA,nowB=headB;
        if(lenA>=lenB)
        {
            for(int i=0;i<distance;i++)
            {
                nowA=nowA->next;
            }
        }
        else{
            for(int i=0;i<distance;i++)
            {
                nowB=nowB->next;
            }
        }
        //查找公共节点
        while(nowA!=nullptr)
        {
            if(nowA==nowB)
            {
                return nowA;
            }
            else{
                nowA=nowA->next;
                nowB=nowB->next;
            }
        }
        return nullptr;        
    }

int main(){
    ListNode* A5=new ListNode(5);
    ListNode* A4=new ListNode(4);
    A4->next=A5;
    ListNode* A3=new ListNode(8);
    A3->next=A4;
    ListNode* A2=new ListNode(1);
    A2->next=A3;
    ListNode* A1=new ListNode(4);
    A1->next=A2;
    ListNode* B3=new ListNode(1);
    B3->next=A3;
    ListNode* B2=new ListNode(0);
    B2->next=B3;
    ListNode* B1=new ListNode(5);
    B1->next=B2;
    getIntersectionNode(A1,B1);
    return 0;
}