/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int width=0;
        queue<pair<TreeNode*,int>>q;
        //initial root node and start index=0 pushed
        q.push({root,0}) ; 

        while(!q.empty()){
            int size = q.size() ; 
            auto it = q.front() ; 
            int min_index = it.second ; 
  
            int firstIndex , lastIndex ; 

           for(int i=0;i<size;i++){
                auto it = q.front() ; 
                q.pop();
             long long int curr_index = it.second - min_index;  //to prevent overflow and index start from 0 onwards in each level
             TreeNode*node = it.first ; 

           //firstIndex  
           if(i==0) firstIndex = curr_index ;
           //lastIndex  
           if(i==size-1) lastIndex = curr_index ;

           //pushed the left node index in queue and node 
           if(node->left!=NULL){
               int left_index = 2*curr_index + 1 ;
               q.push({node->left,left_index});
           }

           //pushed the right node index in queue and node 
           if(node->right!=NULL){
               int right_index = 2*curr_index + 2 ;
               q.push({node->right,right_index});
           }
        }
        //see for max width 
        width = max(width ,lastIndex-firstIndex+1)   ;
        }
        return width;
    }
};
