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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        ListNode*temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        if(count==n){
            temp = head;
            head = head->next ;
            delete temp;
            return head;
        }
        temp = head;
        count = count - n;
        int i = 0;
        while(i!=count-1 ){
            i++;
            temp = temp->next;
        }
        ListNode*temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return head;
    }
};