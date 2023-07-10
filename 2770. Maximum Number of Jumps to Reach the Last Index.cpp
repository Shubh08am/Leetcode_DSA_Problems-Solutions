class Solution {
public: 
    int dp[1001] ; 
    int solve(int ind , vector<int>&nums,int target){
        if(ind==0) return 0; 
    
        if(dp[ind]!=-1) return dp[ind]; 
        
        int res = -1e8;  
        
        for (int i=ind-1; i>=0;i--){
            int diff = nums[ind]-nums[i]; 
            if(diff>=-target && diff<= target){ 
                res = max(res,1+solve(i,nums,target)); 
        
            } 
        }
    return dp[ind]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp)); 
        int ans = solve(nums.size()-1,nums,target); 
        return ans <= 0 ?-1 : ans ;
    }
};
