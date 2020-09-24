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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result=new ListNode(0);
        result->next=head;
        head=result;
        ListNode* target=result;
        while(n--&&head->next!=NULL)head=head->next;
        while(head->next!=NULL){
            head=head->next;
            target=target->next;
        }
        target->next=target->next->next;
        return result->next;
    }
};
