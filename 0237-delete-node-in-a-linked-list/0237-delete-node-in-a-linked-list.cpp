class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node's value into the current node
        node->val = node->next->val;
        
        // Save the next node to delete its memory
        ListNode* temp = node->next;
        
        // Bypass the next node
        node->next = node->next->next;
        
        // Free allocated memory (good practice in C++)
        delete temp;
    }
};