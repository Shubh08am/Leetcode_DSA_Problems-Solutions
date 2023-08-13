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

    ListNode*merge2ListRec(ListNode*left,ListNode*right){
        if(!left) return right;
        if(!right) return left;

        if(left->val < right->val){
            left->next = merge2ListRec(left->next,right) ; 
            return left ; 
        }
        else{
            right->next = merge2ListRec(left,right->next) ; 
            return right ; 
        }
    }
     ListNode*merge2ListIter(ListNode*left,ListNode*right){
        if(!left) return right;
        if(!right) return left;
        ListNode*dummy = new ListNode(-1) ; 
        ListNode*ans = dummy; 

        while(left && right){ 
            if(left->val < right->val){
                dummy->next = left ; 
                left = left->next ; 
            }
            else{
                dummy->next = right ; 
                right = right->next ; 
            }
            dummy=dummy->next;
        }
        dummy->next = (!left)?right:left ; 
        return ans->next;
    }
    ListNode*partitionAndMerge(int start,int end,vector<ListNode*>& lists) {
        if(start>end) return NULL; 
        if(start==end) return lists[start] ; 

        int mid = start + (end-start)/2 ; 

        ListNode*left = partitionAndMerge(start,mid,lists) ; 
        ListNode*right = partitionAndMerge(mid+1,end,lists) ; 

    //    return merge2ListRec(left,right);
        return merge2ListIter(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //O(Nlogk) -> log (k) height of tree and Total Nodes = N
        int k = lists.size() ;
        return partitionAndMerge(0,k-1,lists) ;
    }
};
