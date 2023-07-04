class Solution {
public:
    void findCombination(int ind,int target,vector<int>& candidates, vector<vector<int>>&ans,vector<int>& ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
 
        for(int i=ind;i<candidates.size();i++){
            //avoid same set same level duplicate recursion call
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            //pick
            if(candidates[i]<=target){
                ds.push_back(candidates[i]); 
                findCombination(i+1,target-candidates[i],candidates,ans,ds) ; 
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        findCombination(0,target,candidates,ans,ds); 
        return ans;
    }
};
