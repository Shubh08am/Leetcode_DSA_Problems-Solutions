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
    ListNode*reverseLL(ListNode*head){
        ListNode*prev = NULL , *curr = head ; 
        while(curr){
            ListNode*forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
    return prev;
    }    
    ListNode* doubleIt(ListNode* head) {
         vector<int>v; 
        ListNode*h = head , *dummy = new ListNode(0); 
        while(h){
            v.push_back(h->val) ;
            h=h->next;
        }
    //    for(auto it : v) cout<<it<<" ";
 reverse(v.begin(),v.end()) ; 
         ListNode*p = dummy ; 
        
        int carry = 0 ; 
        
        for(int i=0;i<v.size();i++){
            int sum = (1ll*v[i]*2)  + carry ; 
            carry = sum/10 ;
            dummy->next = new ListNode((sum)%10) ; 
            dummy=dummy->next;
       //     cout<<dummy->val<<" ";
        }
        if(carry>0){ dummy->next = new ListNode(carry) ; 
            dummy=dummy->next;
                 }
        
    return reverseLL(p->next) ;
    }
};
