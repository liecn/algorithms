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
    ListNode* middleNode(ListNode* head) {
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* s1=s;
        ListNode* s2=s;
        while(s2->next&&s2->next->next){
            s1=s1->next;
            s2=s2->next->next;
        }
        return s1->next;
    }
};
