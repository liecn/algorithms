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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result=new ListNode(0);
        result->next=head;
        ListNode* part=result;
        while(part->next!=NULL&&part->next->next!=NULL){
            ListNode* mid=part->next;
            part->next=part->next->next;
            mid->next=part->next->next;
            part->next->next=mid;              
            part=part->next->next;
        }
        return result->next;
    }
};
