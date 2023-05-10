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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       //m -> row 
       //n->col
       //head->spiral order
       vector<vector<int>>spiral(m,vector<int>(n,-1));

       int startingRow=0,lastRow=m-1;
       int startingCol=0,lastCol=n-1; 
       int value=0;

       while(value<=m*n && head!=NULL){
            //startingRow
           int i=startingCol;
           while(i<=lastCol){
                if(head==NULL) break;
                spiral[startingRow][i]=head->val;
                head=head->next;
                value++;i++;
           }
           startingRow++;
 
           //lastCol 
          i=startingRow;
          while(i<=lastRow){
               if(head==NULL) break;
              spiral[i][lastCol]=head->val;
              head=head->next;
              value++;i++;
          }
          lastCol--;
 
          //lastRow
          i=lastCol;
          while(i>=startingCol){
               if(head==NULL) break;
              spiral[lastRow][i]=head->val;
              head=head->next;
              value++;i--;
          }
            lastRow--;
 
          //startingCol
           i=lastRow;
           while(i>=startingRow){
                if(head==NULL) break;
               spiral[i][startingCol]=head->val;
               head=head->next;
               value++;i--;
           }
           startingCol++; 
       }
       return spiral;
    }
};
