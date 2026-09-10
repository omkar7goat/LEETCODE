class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* a=head;int n=0;
        while(a!=NULL){
            n++;a=a->next;
        }
        if(n>2){
           a=head;ListNode*b=head->next;
           ListNode*c=b->next; int u=0;
           ListNode * d=b;
           while(c!=NULL ){
             if(u%2==0){
                a->next=c;u=1;a=a->next;
             }
             else{
                b->next=c;u=0;b=b->next;
             }
             c=c->next;
           }
           a->next=d;
           b->next=NULL;
        }
        return head;
    }
};