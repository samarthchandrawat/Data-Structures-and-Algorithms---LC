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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL) {
            
            return NULL;
        }
        
        ListNode* start = new ListNode(0);
        
        ListNode* fast = start;
        ListNode* slow = start;
        start->next = head;
        
        
        while(n--) {
            
            fast = fast->next;
        }
        
        while(fast->next != NULL) {
            
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* to_delete = slow->next;
        
        slow->next = slow->next->next;
        
        delete to_delete;
        to_delete = NULL;
        
        return start->next;
    }
};