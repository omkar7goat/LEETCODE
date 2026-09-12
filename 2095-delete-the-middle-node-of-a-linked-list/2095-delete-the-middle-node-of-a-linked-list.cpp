/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* temp =head;
        while(temp!=NULL){
            n++;temp=temp->next;
        }
        int g=n;
        if(g==1){
            return NULL;
        }
        n=n/2;
        temp=head;
        while(true){
            temp=temp->next;
            n--;
            if(n==0)break;
        }
        ListNode* a=head;
        while(a ->next !=temp && a!=NULL){
            a=a->next;
        }
        
            a->next=a->next->next;
        return head;
    }
};