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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        else if(list2->val >= list1->val){
            //recursive call take smaller one as next node
            list1->next = mergeTwoLists(list1->next,list2);
             return list1;
        }
        else if(list2->val < list1->val){
            //recursive call take smaller one as next node
            list2->next = mergeTwoLists(list1,list2->next);
             return list2;
        }
        return NULL;
    }
};
