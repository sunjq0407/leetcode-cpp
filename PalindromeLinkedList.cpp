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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        if(!head->next->next) {
            if(head->val==head->next->val) return true;
            else return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = reverseList(slow);
        while(list2) {
            if(head->val!=list2->val) return false;
            head = head->next;
            list2 = list2->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        head->next = NULL;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};