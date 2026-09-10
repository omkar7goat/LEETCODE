class Solution {
public:
   
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* a = head;
        while(a!=NULL){
            n++;a=a->next;
        }
        if(n==1)return true;
        if(n==2){
            if(head->val!=head->next->val)return false;
            return true;
        }
        if(n==3){
            return(head->val==head->next->next->val);
        }
        int k=n/2;
        a=head;
        
        
        int g=1;
        while(g<k){
            g++;a=a->next;
        }
        ListNode* b=a->next;if(n%2!=0)b=b->next;
        a->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=head;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;prev=curr;curr=nex;
        }
        while(prev!=NULL && b!=NULL){
            if(prev->val!=b->val)return false;prev=prev->next;b=b->next;
        }
        return true;

    }
};