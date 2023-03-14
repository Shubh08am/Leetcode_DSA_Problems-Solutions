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
    int dfs(TreeNode*root,int sum){
        if(root==NULL) return 0;
          
        sum=sum*10+root->val ; 

        //at leaf node 
        if(root->left==NULL && root->right==NULL) return sum ; 

        return dfs(root->left,sum) + dfs(root->right,sum); //else go left and right and see sum
    }
    int sumNumbers(TreeNode* root) {
        // Many Approaches DFS + BFS + Morris Traversal + Iterative(Using Stack)
       //  return dfs(root,0); 
      // using, BFS 
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    int res=0; 
    
    while(!q.empty()){
        auto node = q.front().first;
       int value = q.front().second;

        q.pop();
        value = value*10 + node->val ; 

        //left exist 
        if(node->left != NULL){
             q.push({node->left,value});  
          //   cout<<node->left->val<<"l- ";
          // cout<<value<<"l- ";      
             }
         //right exist 
          if(node->right != NULL) {
            q.push({node->right,value});
           // cout<<node->right->val<<"r- ";
          // cout<<value<<"r- ";
            }
        
        //if at leaf node than only take sum 
        if(node->left==NULL && node->right==NULL){ 
            res+=value;
        }
    }
    return res;
    }
};
