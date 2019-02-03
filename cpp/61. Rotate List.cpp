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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        ListNode* r=head;
        int n=1;
        while(head->next){
            head=head->next;
            n++;
        }
        head->next=r;
        k=k%n;
        k=n-k;
        cout<<k;
        while(k--)head=head->next;
        r=head->next;
        head->next=NULL;
        return r;
    }
};
