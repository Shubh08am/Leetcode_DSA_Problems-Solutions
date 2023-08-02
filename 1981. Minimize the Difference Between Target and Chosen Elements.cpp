class Solution {
public:
    int solve(int ind,int n,int m,vector<vector<int>>& mat, int target,int sum,vector<vector<int>>&dp) {
        if(ind==n){
            return abs(target-sum) ;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int curr = INT_MAX;
        for(int i=0;i<m;i++){
            curr=min(curr,solve(ind+1,n,m,mat,target,sum+mat[ind][i],dp));
          //  cout<<curr<<" ";
        }
        return dp[ind][sum] = curr;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size() , m = mat[0].size() ; 
        vector<vector<int>>dp(n+1,vector<int>(343000,-1));
        return solve(0,n,m,mat,target,0,dp);
    }
};
