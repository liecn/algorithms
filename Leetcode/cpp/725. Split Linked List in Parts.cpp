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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> r(k);
        ListNode* mid=root;
        int n=0;
        while(mid){
            n++;
            mid=mid->next;
        }
        int num=n/k-1;
        int part=n%k;
        for(int i=0;i<k;i++){
            r[i]=root;
            if(!root)break;
            for(int j=0;j<num+(i<part);j++)root=root->next;
            mid=root->next;
            root->next=NULL;
            root=mid;
        }
        return r;
    }
};
