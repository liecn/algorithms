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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* result=s;
        while(s->next){
            while(s->next&&s->next->val!=val)s=s->next;
            ListNode* m=s->next;
            while(m&&m->val==val)m=m->next;
            s->next=m;
        }
        return result->next;
    }
};
