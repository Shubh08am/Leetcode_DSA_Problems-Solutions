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

int maxDepth(TreeNode* root) {
    int depth=0;
    queue<TreeNode*>q;//stores nodes
        if(root==NULL){
            return 0; //i.e empty
        }
        //else insert root  in queue
        q.push(root);

        while(!q.empty()){
            int size_to_traverse = q.size();//traversing till size of each level
           depth++;
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
            }

        } 
        return depth;
    }
};
