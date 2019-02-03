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
        ListNode* r=new ListNode(0);
        r->next=head;
        ListNode* result=r;
        if(head&&head->next){
            while(r->next&&r->next->next){
                while(r->next->next&&r->next->val!=r->next->next->val)r=r->next;
                if(!r->next->next) break;
                ListNode* s=r->next;
                while(s->next&&s->next->val==s->val)s=s->next;
                r->next=s->next;
            }
        }
        return result->next;
    }
};
