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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode* res = new ListNode(-1);
        ListNode* start = res;
        
        int carry = 0;
        
        while(l1!=NULL || l2!=NULL) {
            
            int temp = 0;
            
            if(l1 != NULL) {
                
                temp = l1->val;    
            }
            
            if(l2 != NULL) {
                
                temp += l2->val;
            }
            
            temp += carry;
            int v = temp%10;
            carry = temp/10;
            
            res->next = new ListNode(v);
            res = res->next;
            
            
            if(l1 != NULL)
                l1 = l1->next;
            
            if(l2 !=NULL)
                l2 = l2->next;
        }
        
        if(carry != 0) {
            
            res->next = new ListNode(carry);
        }
        
        return start->next;
        
        
    }
};