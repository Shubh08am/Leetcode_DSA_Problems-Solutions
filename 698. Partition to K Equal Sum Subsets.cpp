class Solution {
public:
    bool solve(int ind,int curr_sum ,int target, int k, vector<int>& nums,vector<int>&vis) {
        int n = nums.size();
        if(ind>=n) return 0; 
        if (k == 1) return 1;
         
        if (curr_sum == target){
            return solve(0,0,target,k-1,nums,vis);
        }
        
        for (int i = ind; i < n; i++) {
            if (vis[i]) continue;
            if(curr_sum + nums[i] <= target){
            vis[i] = 1;
            if (solve(i+1, curr_sum + nums[i],target,k, nums, vis)) return 1;
            //backtrack
            vis[i] = 0;
            }
        }
        return 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //backtracking approach
         //find total subsets with sum/k 
         int totalSum=0 , n = nums.size();
         vector<int>vis(n,0);
         for(auto&val:nums) totalSum+=val;
        int target = totalSum/k;

         if(totalSum%k!=0 || n<k) return 0;
         return solve(0,0,target,k,nums,vis);  
}
};
