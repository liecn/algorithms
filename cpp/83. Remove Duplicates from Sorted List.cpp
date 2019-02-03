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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* r=head;
        if(r&&r->next){
            ListNode* s=r->next;
            while(r){
                while(s&&r->val==s->val)s=s->next;
                r->next=s;
                r=r->next;
            }
        }
        return head;
    }
};
