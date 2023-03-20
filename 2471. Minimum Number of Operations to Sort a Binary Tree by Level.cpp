class Solution {
public:
    int minSwap(vector<int>&level){
        int n = level.size();
        vector<int>copy=level;
        sort(copy.begin(),copy.end());
        int swapped=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[level[i]] = i ;
        }
      
        for(int i=0;i<n;i++){ 
            //at correct Position
            if(level[i]==copy[i]) {
                continue;
            }
            int prevPos = mp[level[i]] ; 
            int correctElem_WrongPos = mp[copy[i]] ; 
            //swap 
            swapped++;
            //update new position 
            mp[level[i]]=correctElem_WrongPos;
            //correctElem_correctPos assign 
            mp[copy[i]] = prevPos ;
            //also make swapping in original vector level 
        //    cout<<level[prevPos]<<" "<<level[correctElem_WrongPos]<<"\n";
             swap(level[prevPos],level[correctElem_WrongPos]) ;
        }
       return swapped; 
    }
    int minimumOperations(TreeNode* root) {
        int swapped=0;
        if(!root) return 0;
        queue<TreeNode*>q ;
        q.push(root); // root node pushed i.e level 1
        while(!q.empty()){
            int sz = q.size() ;
            vector<int>level;
            while(sz--){
                TreeNode*node = q.front() ; 
                q.pop();
                 level.push_back(node->val);  

                //see for left sub-tree
               if(node->left){
                    q.push(node->left);
                }

                //see for right sub-tree
                if(node->right){
                    q.push(node->right);
                }
            }
            swapped+=minSwap(level);
        //    for(auto it : level) cout<<it<<" ";
       //     cout<<swapped<<"\n";
       //     cout<<"\n";
        } 
    return swapped; 
    }
};
