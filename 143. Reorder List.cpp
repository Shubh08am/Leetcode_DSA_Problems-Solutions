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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        queue<ListNode*>q;
        int cnt=0;
        ListNode*c=head;
        while(c){
            s.push(c);
            q.push(c);
            c=c->next;
            cnt++;
        }
        bool flag = 0 ; 
        if(cnt%2) flag=1;
        cnt/=2;
        while(!s.empty()&&!q.empty()&&cnt--){
            head->next=q.front();cout<<q.front()->val<<" ";
            q.pop();
            head=head->next;
            head->next=s.top(); cout<<s.top()->val<<" ";
            s.pop();     
            head=head->next;
        }
        if(flag)  {
            head->next=q.front();
             head=head->next;
            q.pop();
        }
        head->next=NULL;
    }
};
