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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return 1;
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* s1=s;
        ListNode* s2=s;
        while(s2->next&&s2->next->next){
            s1=s1->next;
            s2=s2->next->next;
        }
        if(s2->next){
            s1->next=NULL;
            s2=reverseList(s2);
        }
        else{
            s2=s2=reverseList(s1->next);
            s1->next=NULL;
        }
        cout<<head->val<<","<<s2->val<<endl;
        while(head->next&&head->val==s2->val){
            head=head->next;
            s2=s2->next;
        }
        if(head->val!=s2->val)return 0;
        else return 1;
        
    }
private:
     ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* s=new ListNode(0);
        s->next=head;
        ListNode* b=head;
        ListNode* c=head->next;
        while(c->next){
            ListNode* e=c->next;
            c->next=b;
            b=c;
            c=e;
        }
        c->next=b;
        s->next->next=NULL;
        s->next=c;
        return s->next;
    }
};
