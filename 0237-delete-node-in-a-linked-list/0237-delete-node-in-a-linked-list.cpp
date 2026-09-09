
class Solution {
public:
    
    void deleteNode(ListNode* node) {
        ListNode*abc;
        while(node->next!=NULL){
            int a=node->val;abc=node;
            int b=node->next->val;
            node->val=b;node=node->next;            
        }
        abc->next=NULL;

    }
};