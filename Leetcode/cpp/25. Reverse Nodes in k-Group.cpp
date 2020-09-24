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
    ListNode* reverseKGroup(ListNode* head, int k) {  
        if(!head)return head;
        ListNode* r = head;
        ListNode* m = head;
        int flag=k;
        while(--flag&&head->next)head=head->next;
        head=head->next;
        if (!flag) {
            ListNode* b=m->next;
            for(int i=0;i<k-1;i++){
                ListNode* e=b->next;
                b->next=m;
                m=b;
                b=e;
            }
            r->next = reverseKGroup(head, k);
        }
        return m;
    }
};
