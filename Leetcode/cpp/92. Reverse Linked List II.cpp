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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* s1=s;
        ListNode* s2=s;
        int k=n-m;
        while(--m&&s1)s1=s1->next;
        while(n--&&s2)s2=s2->next;
        ListNode* end=s2->next;
        ListNode* b=s1->next;
        ListNode* c=b->next;
        for(int i=0;i<k;i++){//reverse
            ListNode* e=c->next;
            c->next=b;
            b=c;
            c=e;
        }
        s1->next->next=end;//连尾
        s1->next=s2; //接头
        return s->next;
    }
};
