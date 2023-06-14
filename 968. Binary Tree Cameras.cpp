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
    int minCameraCover(TreeNode* root) {
        //at parent node -> place or not place camera
        // every child node sees whether parent had camera or not
        // if parent has no camera child need to have camera 
        // if parent have camera immediate child doesn't need camera 

        // dp(x,placeCameraAtX,parentOfXHadCameraOrNot) 
        //placeCameraAtX= 1 , NotplaceCameraAtX = 0 
        //parentOfXHadCameraOrNot = 1 , parentOfXDoesn'tHadCamera = 0 
        //Subtree rooted at x 

        //start from root therefore 
        // ASSUME ROOT NODE , DUMMY PARENT NODE WHICH DOESN'T NEED ANY CAMERA 
        // MIN(dp(root,0,0) , dp(root,1,0))

         // x is parent node -> c1,c2 are child node 

        // CASE - 1 parent node of x does not has camera and x has camera
        // dp(x,1,0) = 1 + min(dp(c1,1,1) , dp(c1,0,1)) + min(dp(c2,1,1) , dp(c2,0,1))
        //1 added because parent had camera 
        //means x has camera than c1, c2 parent has camera now we decide whether c1,c2
        //should have camera or not 

        // CASE - 2 -> parent node of x also has camera and x also has camera
       // dp(x,1,1) = 1 + min(dp(c1,1,1) , dp(c1,0,1)) + min(dp(c2,1,1) , dp(c2,0,1))
        //1 added because parent had camera 
        //means x has camera than c1, c2 parent has camera now we decide whether c1,c2
        //should have camera or not 


       // CASE - 3 -> NO CAMERA AT X BUT X PARENT HAD CAMERA 
        // dp(x,0,1) = min(dp(c1,1,0) , dp(c1,0,0)) + min(dp(c2,1,0) , dp(c2,0,0))


        //CASE-4 -> NO CAMERA AT X AND NO CAMERA AT X PARENT ALSO 
        // FORCE CHILD NODE OF X [c1,c2] TO HAVE A CAMERA 
            // SUB-CASE 1 -> c1 FORCE TO HAVE CAMERA , c2 has its own choice
            // dp(x,0,0) = dp(c1,1,0)  + min(dp(c2,1,0) , dp(c2,0,0))
             // SUB-CASE 2 -> c2 FORCE TO HAVE CAMERA , c1 has its own choice
            // dp(x,0,0) = min(dp(c1,1,0) , dp(c1,0,0)) + dp(c2,1,0) 



      //BASE CASES FOR LEAF NODE 
      // dp(leaf,0,1) = 0 // parent of leaf had camera 
       // dp(leaf,1,0) = 1 // leaf had camera 
        // dp(leaf,1,1) = 1 // leaf had camera  and parent of leaf had camera 
        // dp(leaf,0,0) = infinity // leaf and parent of leaf doesn't have camera 
        // it goes un-monitored than    
   
    dp.clear(); //after every case reset it 
    int ans = min(dfs(root,0,0) , dfs(root,1,0)) ;
    return ans;
    }
    map<pair<TreeNode*,pair<bool,bool>>,int>dp;
    int dfs(TreeNode*root,bool cameraAtX,bool parentXCamera){
        //BASE CASES 
        if(root==NULL){
            if(cameraAtX) return 1<<20;
            else return 0;
        }

        //LEAF NODE 
        if(root->left == NULL && root->right==NULL){
            if(cameraAtX) return 1; //dp(leaf,1,1) =1 , //dp(leaf,1,0) =1
            else{
                if(parentXCamera) return 0; //dp(leaf,0,1) =0
                else return 1<<20; //dp(leaf,0,0) = INFINITY
            }
        }

        //4 CASES 

        //ALREADY SUB-PROBLEM SOLVED
       if(dp.find({root,{cameraAtX,parentXCamera}}) != dp.end()){
           return dp[{root,{cameraAtX,parentXCamera}}];
       }


       //RECURRENCE 
       //CAMERA AT X , parent of x can have or not camera
       if(cameraAtX){
        return dp[{root,{cameraAtX,parentXCamera}}] = 
                        1 + min(dfs(root->left,0,1),dfs(root->left,1,1)) 
                             +  min(dfs(root->right,0,1),dfs(root->right,1,1));
       }
       else{
           //   no camera at x and camera at parent of x 
           if(parentXCamera){
            return  dp[{root,{cameraAtX,parentXCamera}}] = 
                        0 + min(dfs(root->left,0,0),dfs(root->left,1,0)) 
                             +  min(dfs(root->right,0,0),dfs(root->right,1,0));  
           }
           else{
                // no camera at x and no camera at parent of x
                //child of x forced to have camera 
                int c1 = dfs(root->left,1,0) + min(dfs(root->right,0,0),dfs(root->right,1,0));
                int c2 = dfs(root->right,1,0) + min(dfs(root->left,0,0),dfs(root->left,1,0));
  
                 return  dp[{root,{cameraAtX,parentXCamera}}] = min(c1,c2) ;
           }
       }
    }
};
