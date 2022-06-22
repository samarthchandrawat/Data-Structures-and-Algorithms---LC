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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
     
        ListNode* prev = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* senitel = prev;
        
        while( curr!=NULL && curr->next != NULL) {
            
            ListNode* nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = curr;
            prev->next = nxt;
            
            prev = curr;
            curr = curr->next;
        }
        
        return senitel->next;
    }
};