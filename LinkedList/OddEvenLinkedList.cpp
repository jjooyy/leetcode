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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy(0);
        ListNode edummy(0);
        ListNode *odd = &dummy;
        ListNode *even = &edummy;
        int count = 1;
        while(head ) {
            if(count % 2 ) {
                odd->next = head;
                odd = odd->next;
            }
            
            else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            count++;
        }
        odd->next = edummy.next;
        even->next = NULL;
        return dummy.next;
    }
};
