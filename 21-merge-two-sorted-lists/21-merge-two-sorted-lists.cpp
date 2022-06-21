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
    
    void rec_helper(ListNode* list1, ListNode* list2, ListNode* res) {
        
        if(list1 == NULL) {
            
            while(list2 !=NULL) {
                
                res->next = new ListNode(list2->val);
                res = res->next;
                list2 = list2->next;
            }
            
            return;
        }
        
        if(list2 == NULL) {
            
            while(list1 !=NULL) {
                
                res->next = new ListNode(list1->val);
                res = res->next;
                list1 = list1->next;
            }
            return;
        }
        
        
        if(list1->val < list2->val) {
            
            if(res->val == -101) {
                
                res->val = list1->val;
            } else {
                
                res->next = new ListNode(list1->val);
                res = res->next;
            }
            
            rec_helper(list1->next, list2, res);
            return;
        } else {
            
            if(res->val == -101) {
                
                res->val = list2->val;
            } else {
                
                res->next = new ListNode(list2->val);
                res = res->next;
            }
            rec_helper(list1, list2->next, res);
            return;
        }
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp = new ListNode(-101);
        
        ListNode* res = temp;
        
        if(list1 == NULL) {
            return list2;
        }
        
        if(list2 == NULL) {
            return list1;
        }
        rec_helper(list1, list2, temp);
        
        return res;
    }
};