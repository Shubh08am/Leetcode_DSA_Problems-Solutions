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

    int getDecimalValue(ListNode* head) {

        int len = 0;

long long int ans = 0;

ListNode*temp = head;

while(temp){

temp=temp->next;

len++;

} 

        len--;

temp = head ;

while(temp and len>=0) {

ans+=((1LL<<len) *temp->val) ;

len--;

temp=temp->next;

}

return ans;

    }

};
