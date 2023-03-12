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
    void insertattail(ListNode*& dummy, int val){
    ListNode* newNode = new ListNode(val);
    if (dummy==NULL) {
        dummy = newNode;
        return;
    }
    ListNode* temp = dummy;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 
        priority_queue<int,vector<int>,greater<int>>mpq; //min-heap created
        vector<ListNode*>ans;
         for(int i=0;i<n;i++){  
             ListNode*dummy = lists[i];
              while(dummy!=NULL){ //access all nodes of lists
        //        cout<<dummy->val<<" ";
                mpq.push(dummy->val); //all nodes value pushed in mpq
                dummy=dummy->next;
            }
        }
    //    cout<<"\n"<<mpq.size()<<"\n";

        while(!mpq.empty()){ 
            ListNode*node= new ListNode(mpq.top());
            mpq.pop();
             ans.push_back(node);
        } 
     //  ans.push_back(NULL); //denotes termination 
    //    cout<<ans.size()<<"\n"; 
    //  for(auto&x : ans) cout<<x->val<<" ";

         if(ans.size()==0) return NULL; //empty lists
         /*
         ListNode*dummy = NULL ;
         int i=0;
         while(i<ans.size()){
         insertattail(dummy,ans[i]->val);
         i++;
         }
         */
         ListNode*dummy = ans[0] , *temp;
         temp=dummy;
         int i=1;
         while(i<ans.size()){
         dummy->next = ans[i];
         dummy=dummy->next;
         i++;
         }
      return temp;
    }
};
