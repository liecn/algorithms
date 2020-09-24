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
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return;
        ListNode* e=head;
        while(e->next->next)e=e->next;
        e->next->next=head->next;
        head->next=e->next;
        e->next=NULL;
        reorderList(head->next->next);
    }
};
