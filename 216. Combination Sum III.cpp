class Solution {
public:
    void solve(int i,int k,int n, vector<int>&ds,vector<vector<int>>&ans){
        if(n==0){
            if(k==0){
                ans.push_back(ds);
            }
            return;
        }
        if(k<0 || i>n) return;

        //pick 
        for(int ind=i;ind<=9;ind++){
            if(ind>n) break;
            ds.push_back(ind) ; 
            solve(ind+1,k-1,n-ind,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};
