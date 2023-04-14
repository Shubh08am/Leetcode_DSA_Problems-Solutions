class Solution {
public:
    // BackTracking 
    void solve(int n,int ind,vector<int>&dummy,int k,vector<vector<int>>&ans){ 
        //Base case
        if(dummy.size()>k){
            return;
        }
        if(dummy.size()==k){
            ans.push_back(dummy);
        }
        for(int i=ind;i<=n;i++){
            dummy.push_back(i);
            solve(n,i+1,dummy,k,ans);
            //backtrack now
            dummy.pop_back();
          }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>dummy;
        solve(n,1,dummy,k,ans);
        return ans;
    }
};
