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
        
        if(head==NULL)
            return NULL;
        
        ListNode* dummy = head;
        int size = 1;
        
        while(dummy->next != NULL) {
            
            size++;
            dummy = dummy->next;
        }
        
        k = k % size;
        int jumps = size - k -1;
        
        ListNode* temp = head;
        
        while(jumps--) {
            
            temp = temp->next;
        }
        
        ListNode* res = head;

        if( k>0 ) {
            
            res = temp->next;

            temp->next = NULL;

            dummy->next = head;
        }
        
        return res;
    }
};