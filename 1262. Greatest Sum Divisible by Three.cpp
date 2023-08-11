class Solution {
public:
    int solve(int ind,int rem,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()) {
            if(rem==0) return 0 ; 
            return -1e6;
        }
        if(dp[ind][rem] !=-1) return dp[ind][rem] ; 
        int take = nums[ind] + solve(ind+1,(rem+nums[ind])%3,nums,dp) ; 
        int notTake = solve(ind+1,rem,nums,dp) ;  
        return dp[ind][rem] = max(take,notTake) ; 
    }
    int maxSumDivThree(vector<int>& nums) {
       // try all ways using dp 
       // now, to reduce n*n -> use mod 
       // n*3 now :) 
       // one state for sum and one for remainder 
       int n = nums.size() ;
       vector<vector<int>>dp(n,vector<int>(4,-1)) ; 
       return solve(0,0,nums,dp) ;  
    }
};
