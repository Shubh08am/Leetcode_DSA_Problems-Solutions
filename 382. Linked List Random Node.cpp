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
    ListNode* dummy ,*hd; int len=0;
    Solution(ListNode* head) {
        dummy=hd=head;
        while(dummy) {
            len++;
            dummy=dummy->next;
        }
        srand(time(0));
    }
    
    int getRandom() {
      //use rand() and compute length of ll in constructor only
        int value = rand()%len;
        //go in ll and return value 
        dummy=hd;
        while(value--){
        dummy=dummy->next;
        }
        return dummy->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
