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

    ListNode* reverseKGroup(ListNode* head, int k) {

        

        if(head == NULL) {

            return NULL;

        }

        

        //step1 : reverse first k nodes

        

        ListNode*next =NULL;

        ListNode*prev =NULL;

        ListNode*curr =head;

        ListNode*temp =head;

          int cnt = 0 ;

         // To check if length of our Linked List is greater than equal to K

      for(int i=0;i<k;i++)

        {

            if(temp==NULL)

            {

                return head;

            }

            temp = temp->next;

        }

        

        while(curr!=NULL and cnt<k){

next = curr->next ; 

        curr->next = prev ; 

            prev = curr ; 

            curr = next ;

            cnt++;

          //len-=k;

        }

              //step2 : recursion

        

        if(next!=NULL){

head->next = reverseKGroup(next,k);

        }

  

        

        // step3: return head of reverse linked list i.e prev 

        

        return prev ; 

        

        

    }

};
