/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*curr=head; 
        while(curr){
            if(curr->child){
                // Save the current next and connect the child to next
                Node*nextNode=curr->next; 
                curr->next=curr->child; 
                curr->child->prev=curr;
                curr->child=NULL;
                // Run till the end of the current list and connect last node to saved next
                Node*nextChildNode = curr->next; 
                while(nextChildNode->next){
                    nextChildNode=nextChildNode->next;
                }
                nextChildNode->next=nextNode;
              if(nextNode)  nextNode->prev=nextChildNode;
            }
            curr=curr->next;
        }
    return head;
    }
};
