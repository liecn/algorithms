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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* s=head;
        ListNode* even=head->next;
        bool num=0;
        while(s->next&&s->next->next){
            ListNode* mid=s->next;
            s->next=s->next->next;
            s=mid; 
            num=!num;
        }
        if(!num)s->next=even;
        else {
            s->next->next=even;
            s->next=NULL;
        }
        return head;
    }
};
