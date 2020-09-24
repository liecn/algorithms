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
        if(!head||!head->next) return head;
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* b=head;
        ListNode* c=head->next;
        while(c->next){
            ListNode* e=c->next;
            c->next=b;
            b=c;
            c=e;
        }
        c->next=b;
        s->next->next=NULL;
        s->next=c;
        return s->next;
    }
};
