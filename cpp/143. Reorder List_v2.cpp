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
        while(head&&head->next&&head->next->next){
            ListNode* e=head;
            while(e->next->next)e=e->next;
            e->next->next=head->next;
            head->next=e->next;
            e->next=NULL;
            head=head->next->next;
        }
    }
};
