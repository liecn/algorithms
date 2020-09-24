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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(!n)return NULL;
        ListNode* result=new ListNode(0);
        ListNode* s=result;
        vector<int> head(n);
        for(int i=0;i<n;i++){
            if(lists[i]) head[i]=lists[i]->val;
            else head[i]=INT_MAX;
        }
        int flag=min_element(head.begin(),head.end())-head.begin();
        while(head[flag]<INT_MAX){
            result->next=lists[flag];
            result=result->next;
            if(lists[flag]->next){
                lists[flag]=lists[flag]->next;
                head[flag]=lists[flag]->val;
            }
            else head[flag]=INT_MAX;
            flag=min_element(head.begin(),head.end())-head.begin();
        }
        return s->next;
    }
};
