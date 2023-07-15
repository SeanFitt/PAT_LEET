#include<stack>
using namespace std;
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
    ListNode* reverseList1(ListNode* head) {
        stack<int> cache_L;
        ListNode* now=head;
        while(now!=nullptr)
        {
            cache_L.push(now->val);
            ListNode* d_l=now;
            now=now->next;
            delete(d_l);
        }
        //size=0,return
        if(cache_L.empty())
        return nullptr;
        //else
        ListNode* new_head=new ListNode();
        now=new_head;
        ListNode* pre=nullptr;
        while(!cache_L.empty())
        {
            int val=cache_L.top();
            cache_L.pop();
            now->val=val;
            if(pre!=nullptr)
            {
                pre->next=now;
            }
            now->val=val;
            pre=now;
            now=new ListNode();
        }
        delete(now);
        return new_head;
    }
    ListNode* reverseList(ListNode* head){
        //空间换时间的策略
        //创建一维二级指针数组，用于后续反向遍历
        ListNode** L=(ListNode**)malloc(sizeof(ListNode*)*10001);
        int len=0;
        ListNode* now=head;
        //如果head为空指针，特殊处理
        if(now==nullptr)
        return now;
        //遍历，将链表节点地址存入一维二级指针数组
        while(now!=nullptr)
        {
            L[len++]=now;
            now=now->next;
        }
        //需要返回的新的头节点
        ListNode* new_head=L[--len];
        //反向遍历，翻转表格
        while(len!=0)
        {
            L[len]->next=L[len-1];
            len--;
        }
        //将翻转后的尾节点的next置为空指针
        L[0]->next=nullptr;
        return new_head;
    }
};
int main(){

}