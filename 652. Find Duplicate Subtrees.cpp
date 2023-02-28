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
     string structureOfSubTree(TreeNode* root,vector<TreeNode*>&result,unordered_map<string,int>&structure){
       string left_structure="",right_structure="",current="";
       current=to_string(root->val);
       //go left first 
       if(root==NULL) return "NULL";
       if(root->left!=NULL){
           left_structure=structureOfSubTree(root->left,result,structure);
       }
       //go right than 
       if(root->right!=NULL){
           right_structure=structureOfSubTree(root->right,result,structure);
       }
       //now,at node see the structure and insert in structure 
       //before going left tell we are going left and same for right i.e delimeter
       string newStructure = current + "left"+left_structure +"right"+right_structure ;
        structure[newStructure]++;
        //if frequency becomes 2 than Duplicate Subtrees
       if( structure[newStructure]==2){
           result.push_back(root);
       }
       return newStructure;
     }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //compare the structure of sub-trees 
        //first go left than right than at node i.e post order traversal 
        vector<TreeNode*>result;
        unordered_map<string,int>structure;
        structureOfSubTree(root,result,structure);
        return result;
    }
};
