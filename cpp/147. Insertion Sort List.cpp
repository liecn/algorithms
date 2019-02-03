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
    ListNode* insertionSortList(ListNode* head) {
        ListNode s=ListNode(-1);
        s.next=head;
        ListNode* cur=head;
        while(cur&&cur->next){
            ListNode* r=&s;
            while(cur->next&&cur->val<cur->next->val)cur=cur->next;
            ListNode* t=cur->next;
            if(t){
                cur->next=cur->next->next;
                while(r->next&&r->next->val<cur->val&&r->next->val<t->val)r=r->next;
                t->next=r->next;  
                r->next=t;
            }
        }
        return s.next;
    }
};
