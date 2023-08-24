class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size() , maxi = INT_MIN ;  
        vector<int>dp(n+1,1) ; 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>=nums[j] && dp[i]<=dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(dp[i],maxi);
        }
        return n-maxi;
    }
};
