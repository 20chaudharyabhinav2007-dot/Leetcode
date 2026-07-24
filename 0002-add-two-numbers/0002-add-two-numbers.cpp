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
        ListNode *test = new ListNode(0);
        ListNode *dum = test ;
         int j = 0;
         while( l1 !=NULL || l2 != NULL || j !=0 ){
            int sum = j;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
             j = sum / 10;
             dum->next = new ListNode(sum % 10);
            dum = dum->next;
        }

        return test->next;
    }
            
         
    
};