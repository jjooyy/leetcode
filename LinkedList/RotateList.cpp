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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || (!k)) {
            return head;
        }
        ListNode* dummy;
        dummy->next = head;
        int count = 0;
        ListNode* runner = head;
        while(runner) {
            runner = runner->next;
            count++;
        }
        k %= count;
        int start = count - k;
        if(k) {
            count = 0;
            runner = head;
            while(count < start - 1) {
                count++;
                runner = runner -> next;
            }
            dummy->next = runner->next;
            runner->next = NULL;
            runner = dummy->next;
            while(runner->next) {
                runner = runner->next;
            }
            runner->next = head;
        }
        else {
            dummy->next = head;
        }
        return dummy->next;
    }
};
