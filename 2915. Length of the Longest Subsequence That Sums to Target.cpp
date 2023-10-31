class Solution {
public:
    int solve(int ind,vector<int>& nums, int target,vector<vector<int>>&dp) {
        if(ind==-1){
            return target==0?0:-1e9;
        }
        int &val = dp[ind][target];
        if(val!=-1) return val;
        int notTake = solve(ind-1,nums,target,dp); 
        int take=INT_MIN; 
        if(target>=nums[ind]){
            take=1+solve(ind-1,nums,target-nums[ind],dp);
        }
        return val=max(take,notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size() ; 
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1)); 
        int ans = solve(n-1,nums,target,dp);
        return ans>=0?ans:-1;
    }
};
