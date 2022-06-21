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
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        
        int count = 1;
        
        while(fast!= NULL) {
            
            fast = fast->next;
            
            if(count%2 == 0) {
                
                prev = slow;
                slow = slow->next;
            }
            
            count++;
        }
        
        prev->next = prev->next->next;
        delete slow;
        slow = NULL;
        
        return head;
    }
};