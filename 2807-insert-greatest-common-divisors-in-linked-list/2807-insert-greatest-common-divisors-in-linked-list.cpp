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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        while (temp->next != NULL) {
            ListNode* temp2 = temp->next;
            int g = gcd(temp->val, temp2->val);
            ListNode* n = new ListNode(g);
            n->next = temp2;
            temp->next = n;
            temp = temp2;
        }
        return head;
    }
};