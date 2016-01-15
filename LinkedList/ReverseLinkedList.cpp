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
    ListNode* reverseList(ListNode* head) {
        if((!head) ||(!head->next)) {
            return head;
        }
        else {
            ListNode *node = reverseList(head->next);
            ListNode* newHead = node;
            while(node->next) {
                node = node->next;
            }
            node->next = head;
            head->next = NULL;
            return newHead;
        }
    }
};
