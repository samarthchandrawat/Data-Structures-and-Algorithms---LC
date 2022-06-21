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
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        int count = 0;
        
        while(fast->next!= NULL) {
            
            fast = fast->next;
            
            count++;
            
            if(count%2 == 0) {
                
                slow = slow->next;
            }
        }

        slow->next = slow->next->next;
        
        return head;
    }
};