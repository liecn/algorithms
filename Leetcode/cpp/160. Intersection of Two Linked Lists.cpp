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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *s1=headA;
        ListNode *s2=headB;
        while(1){
            if(s1==s2)return s1;
            s1=s1==NULL?headB:s1->next;
            s2=s2==NULL?headA:s2->next;
        }
    }
};
