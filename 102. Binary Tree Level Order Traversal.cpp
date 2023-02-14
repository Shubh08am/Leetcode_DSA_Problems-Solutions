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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level order traversal 
        vector<vector<int>>ans;
        queue<TreeNode*>q;//stores nodes
        if(root==NULL){
            return ans; //i.e empty
        }
        //else insert root  in queue
        q.push(root);

        while(!q.empty()){
            vector<int>level;
            int size_to_traverse = q.size();//traversing till size of each level

            for(int i=0;i<size_to_traverse;i++){
                //see if left and right exist if yes insert that nodes in queue
                TreeNode*node = q.front();
                q.pop();//remove from queue 
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            //now,insert all level nodes in level vector 
            level.push_back(node->val);
            }
       //store level vector in ans now --> as nodes get inserted level vise 
       ans.push_back(level);
        } 
        return ans;
    }
};
