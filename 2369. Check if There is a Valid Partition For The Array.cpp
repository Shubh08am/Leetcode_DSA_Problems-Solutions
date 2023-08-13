class Solution {
public:
    bool validPartition(vector<int>& nums) {
        //try all possible ways using dp should work 
        int n = nums.size() ; 
        int dp[n+1] ; 
        memset(dp,0,sizeof(dp)) ; 
        dp[n]=1;

        for(int i=n-2;i>=0;i--){
            int curr=0;
            if(nums[i]==nums[i+1]){
                curr|=dp[i+2];
            }
            if(i<n-2 && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                curr|=dp[i+3];
            }
            if(i<n-2 && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1){
                curr|=dp[i+3];
            }
            dp[i]=curr;
        }
    return dp[0];
    }
};
