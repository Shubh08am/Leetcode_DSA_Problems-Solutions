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
    bool hasCycle(ListNode *head) {
    
     /* APPROACH -1 USING MAPS  
     
        // T.C -> O(N) AND S.C-> O(N)
        // N -> NUMBER OF NODES IN L.L
        map<ListNode*,bool>visited ; 
        ListNode*temp = head ;  
        if(head == NULL) return false; 
        while(temp!=NULL){
            if(visited[temp]==true){
                return true;
            }
            visited[temp] = true ;
            temp=temp->next;
        }
        return false;
        */
        
        // APPROACH-2   Floyd’s Algorithm
        // T.C -> O(N) AND S.C-> O(1)
        // N -> NUMBER OF NODES IN L.L
        
         if(head == NULL) return false;
        
        ListNode*slow = head;
        ListNode*fast = head->next; 
        // we move slow one time and fast 2 time
        // If at any time fast and slow meet it indicates loop is present
        while(slow!=NULL and fast!=NULL){
            slow = slow->next ;
            fast= fast->next; 

            if(fast !=NULL){ // moved for 2nd time
                fast= fast->next; 
            }
            
            // checking if slow and fast meets
            if(slow==fast) return true ;
        }
        return false;
    }
};
