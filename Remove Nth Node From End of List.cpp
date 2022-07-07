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

    ListNode* removeNthFromEnd(ListNode* head, int n) {

      if(head==NULL || head->next == NULL){

          return NULL;

          

      }  

        

        int len = 0 ;

        ListNode*temp = head ; 

        while(temp){

            len++ ;

            temp=temp->next;

        }

        

        int target = len-n+1 ; 

        if(target==1) {

            head=head->next;

            return head;

        }

        int cnt=2;

        temp = head ; 

        while(temp and cnt<target){

            temp=temp->next;

            cnt++;

        }

     if(temp->next!=NULL)   temp->next = temp->next->next ; 

     //  temp->next = NULL; 

       // delete (temp->next) ; 

        

        return head ;

    }

};
