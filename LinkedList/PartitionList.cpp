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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0), half(0);
        ListNode *less = &dummy;
        ListNode *greater = &half;
        ListNode *node;
        if(!head) {
            return head;
        }
        node = head;
        while(node) {
            if(node->val < x) {
                less->next = node;
                less = less->next;
            }
            else {
                greater->next = node;
                greater = greater->next;
            }
            node = node->next;
        }
        less->next = half.next;
        greater->next = NULL;
        return dummy.next;
    }
};
