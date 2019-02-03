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
        struct cmp{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }    
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> min_heap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) min_heap.push(lists[i]); //only push not empty node
        }
        ListNode* s = new ListNode(0);
        ListNode* cur = s;
        while(!min_heap.empty()){
            cur->next = min_heap.top();
            cur=cur->next;
            min_heap.pop();
            if(cur->next) min_heap.push(cur->next);
            
        }
        return s->next;
    }
};
