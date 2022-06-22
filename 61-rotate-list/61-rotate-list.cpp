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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return NULL;
        
        ListNode* tail = head;
        int size = 1;
        
        while(tail->next != NULL) {
            
            size++;
            tail = tail->next;
        }
        
        k = k % size;
        
        if(k==0)
            return head;
        
        tail->next = head;
        
        for(int i=0; i<size-k-1; i++) {
            
            head = head->next;
        }
        
        ListNode* res = head->next;
        head->next = NULL;
        
        return res;
    }
};