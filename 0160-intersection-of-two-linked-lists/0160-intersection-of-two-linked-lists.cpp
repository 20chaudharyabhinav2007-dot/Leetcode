/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        ListNode*temp = headA;
        ListNode*temp1 = headB;
        while(temp!= NULL){
            s1.push(temp);
            temp = temp -> next;
        }
        while(temp1 != NULL){
            s2.push(temp1);
            temp1 = temp1 -> next;
        }
        ListNode* Inter = NULL;
        while(!s1.empty() && !s2.empty()){
            if(s1.top() == s2.top()){
                Inter = s1.top();
                s1.pop();
                s2.pop();
            }else{
                break;
            }
        }
        return Inter;
    }
};