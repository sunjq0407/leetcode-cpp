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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL;
        ListNode * prev = NULL;
        int carry = 0;
        while(l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            ListNode * cur = new ListNode (sum%10);
            if(!head) head = cur;
            if(prev) prev->next = cur;
            prev = cur;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry) {
            ListNode * cur = new ListNode (carry);
            prev->next = cur;
        }
        return head;
    }
};