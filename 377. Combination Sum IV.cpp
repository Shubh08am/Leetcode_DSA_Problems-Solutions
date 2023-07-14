class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<int>&dp){
        int n = nums.size()  ;
        if(ind==n){
            return 0;
        }
        if(target==0){
            return 1;
        } 
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int i=0;i<n;i++){
            //take
            if(target>=nums[i]){
                ans+=solve(ind,target-nums[i],nums,dp);
            }
        }
    return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        //infinte supply concept from knapsack & coin change 
        vector<int>dp(target+1,-1);
        return solve(0,target,nums,dp);
    }
};
