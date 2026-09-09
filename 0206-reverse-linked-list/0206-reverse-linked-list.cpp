
class Solution {
public:
    void f(ListNode* a){
       if(a==NULL || a->next==NULL)return;
       ListNode* b=a->next;
       f(a->next);
       if(b!=NULL){
        b->next=a;a->next=NULL;
       }
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* ans=head;
        while( ans->next!=NULL)ans=ans->next;
        f(head);
        return ans;
    }
};