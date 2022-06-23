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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int flag = 1;
        ListNode* res = new ListNode(-10001);
        ListNode* senitel = res;
        
        while(flag == 1) {
            
            int least_x = -1;
            
            int least_val = INT_MAX;
            
            for(int i=0; i<lists.size(); i++) {
                
                if(lists[i] != NULL) {
                     
                    if(lists[i]->val < least_val) {
                        
                        least_val = lists[i]->val;
                        least_x = i;
                    }    
                }
            }
            
            if(least_val == INT_MAX)  {

                flag = 0;
            } else {
                
                res->next = new ListNode(least_val);
                res = res->next;

                lists[least_x] = lists[least_x]->next;
            }
        }
        
        return senitel->next;
    }
};