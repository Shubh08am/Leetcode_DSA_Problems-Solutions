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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       vector<ListNode*>ans; 
       int len = 0 ; 
        ListNode*temp=head;
       while(temp){
           temp=temp->next;
           len++;
       } 
       int newLen = (len+k-1)/k ;
       int oldLen = len/k;
       int extraNodePerGroup = len%k;

       // extraNodePerGroup jitne group bnega jiski len newLen hogi 
        int i=0;
        ListNode*newHead=head;
       // cout << len << " "<< newLen << " "<< oldLen << " "<< extraNodePerGroup << "\n";
        
        while(newHead && i<extraNodePerGroup){
            ListNode*dummy = new ListNode(-1) ; 
            ListNode*copy = dummy; 

            for(int j=0;(j<newLen && newHead) ;j++){
                dummy->next = new ListNode(newHead->val) ; 
                newHead = newHead->next;
                dummy=dummy->next;
            //    cout << dummy->val << " ";
            }
          //  cout<<"\n";
            ans.push_back(copy->next);
            i++;
        }
        i=0;   
        while(newHead && i<oldLen*k){
            ListNode*dummy = new ListNode(-1) ; 
            ListNode*copy = dummy; 

            for(int j=0;(j<oldLen && newHead) ;j++){
                dummy->next = new ListNode(newHead->val) ; 
                newHead = newHead->next;
                dummy=dummy->next;
            //    cout << dummy->val << " ";
            }
            ans.push_back(copy->next);
            // cout<<"\n";
            i++;
        }
        while(ans.size()!=k) ans.push_back(NULL);
        return ans;
    }
};
