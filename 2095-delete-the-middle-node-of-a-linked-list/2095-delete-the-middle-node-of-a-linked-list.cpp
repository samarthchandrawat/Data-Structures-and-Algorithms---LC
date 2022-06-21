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
        
        if(head->next == NULL) {
            return NULL;
        }
        
        int size = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            
            size++;
            temp = temp->next;
        }
        
        int jumps = (size/2) -1;
        
        temp = head;
        
        while(jumps--) {
            
            temp = temp->next;
        }
        
        ListNode* to_delete = temp->next;
        
        temp->next = temp->next->next;
        
        delete to_delete;
        to_delete = NULL;
        
        return head;
    }
};