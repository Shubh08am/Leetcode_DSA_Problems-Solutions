/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentTrack, TreeNode* target){
      queue<TreeNode*>q;
        q.push(root) ; 

        while(!q.empty()){
                TreeNode*curr=q.front();
                q.pop();

                //check on left if node exist 
                if(curr->left){
                 q.push(curr->left);
                 parentTrack[curr->left]=curr; //curr->left is child and curr is parent
                }
                 //check on right if node exist 
                if(curr->right){
                 q.push(curr->right);
                 parentTrack[curr->right]=curr; //curr->left is child and curr is parent
                }
        }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        //tracking all parent 
        markParent(root,parentTrack,target);
        //visited map that tells which nodes has been visited
         unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target) ; 
        //make target node as visited 
        visited[target]=true;
        int dist=0;

        while(!q.empty()){
            //bfs traversal to go to upto k levels from target node 
            int size=q.size();
            
            //k-levels reached
            if(dist==k) break;
             dist++;
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();

                //check on left if node exist and it is not visited
                if(curr->left and !visited[curr->left]){
                 q.push(curr->left);
                 visited[curr->left]=true;
                }
                //check on right if node exist and it is not visited
                if(curr->right and !visited[curr->right]){
                 q.push(curr->right);
                 visited[curr->right]=true;
                }
                //check on current parent node if exist and it is not visited
                if(parentTrack[curr]and !visited[parentTrack[curr]]){
                 q.push(parentTrack[curr]);
                 visited[parentTrack[curr]]=true;
                } 
            }
        }
        vector<int>res;
       //remaining nodes in queue is our answer
       while(!q.empty()){
           res.push_back(q.front()->val);
           q.pop();
       }
       return res;
    }
};
