/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
            vector<int>v;
    ListNode*p=head,*q=head;
    while(p!=NULL)
    {
      v.push_back(p->val);
        p=p->next;
    }
    
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        q->val=v[i];
        q=q->next;
    }
    return head;
    }
};
