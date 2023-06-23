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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q; //stores nodes and verticalLine  and level 
        map<int,map<int,multiset<int>>>mp; //it stores first -> verticalLine corresponding to it it's level and vertical order corresponding to every level
        vector<vector<int>>ans;

        if(root ==NULL) {
            return ans;
        }

        //Initially, in queue we push root and verticalLine = 0  and level = 0 
        q.push({root,{0,0}}) ;

        while(!q.empty()){
            //take the front of queue 
            auto it = q.front() ; 
            q.pop();
            TreeNode*node = it.first; //as first is a Node 
            int verticalLine = it.second.first ; 
            int level = it.second.second ; 

        //insert node in map 
        mp[verticalLine][level].insert(node->val);

            //see if left exist, if it does push in queue 
            if(node->left != NULL) {
          //since,we go left therefore verticalLine decreases by 1 and going down therefore level increases by 1
                q.push({node->left,{verticalLine-1,level+1}});
            }

             //see if right exist, if it does push in queue 
            if(node->right != NULL) {
          //since,we go right therefore verticalLine increases by 1 and going down therefore level increases by 1
                q.push({node->right,{verticalLine+1,level+1}});
            }

        }

        //now,take value from map and insert in ans 
        for(auto it : mp){ //it = int,map<int,multiset<int>>
            vector<int>verticalorder;
            //now, it.second = map<int,multiset<int>>
            for(auto x:it.second){
                //now, x.second =  multiset<int>  -> insert value from it
                for(auto y : x.second){
                  verticalorder.push_back(y);
                }
            }
            ans.push_back(verticalorder);
        }
        return ans;
    }
};
