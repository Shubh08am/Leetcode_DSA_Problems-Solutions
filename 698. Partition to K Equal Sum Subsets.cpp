class Solution {
public:
    bool solve(int ind,int curr_sum ,int target, int k,int mask, vector<int>& nums,vector<int>&dp) { 
        if (k == 0) {
            return 1;
        }   
        if(dp[mask]!=-1) return dp[mask];

        if (curr_sum == target){
            return solve(0,0,target,k-1,mask,nums,dp);
        }
        for (int j = ind; j < nums.size(); j++) {
            if (mask&(1<<j)) continue;
            if(curr_sum + nums[j] <= target){
          if (solve(j+1, curr_sum + nums[j],target,k,mask|(1<<j),nums, dp)) return dp[mask]=1;
            }
        }
        return dp[mask]= 0;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         //backtracking approach
         //find total subsets with sum/k 
         int totalSum=0 , n = nums.size();
         vector<int>dp(1<<16,-1);
         for(auto&val:nums) totalSum+=val;
        int target = totalSum/k;

         if(totalSum%k!=0 || n<k) return 0;
         return solve(0,0,target,k,0,nums,dp);  
}
};
