class Solution {
public:
    double solve(int ind,vector<int>& nums, int k,vector<vector<double>>&dp) {
        int n = nums.size();
        if(ind==n) return 0; 
        if(k==0) return INT_MIN; 
        if(dp[ind][k]!=-1) return dp[ind][k];
        double sum=0,ans=0;
        for(int pos=ind;pos<n;pos++){
            sum+=nums[pos];
            ans=max(ans,sum/(pos-ind+1)+solve(pos+1,nums,k-1,dp));
        } 
    return dp[ind][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<vector<double>>dp(n,vector<double>(k+1,-1));
        return solve(0,nums,k,dp);
    }
};
