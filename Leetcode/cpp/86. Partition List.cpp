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
        ListNode* r=new ListNode(0);
        r->next=head;
        ListNode* result=r;
        while(r->next&&r->next->val<x)r=r->next;
        ListNode* s=r;
        while(s->next){
            while(s->next&&!(s->next->val<x))s=s->next;
            ListNode* t=s;
            while(t->next&&t->next->val<x)t=t->next;
            ListNode* mid=t->next;
            t->next=r->next;
            r->next=s->next;
            s->next=mid;
            r=t;
        }
        return result->next;
        
    }
};
