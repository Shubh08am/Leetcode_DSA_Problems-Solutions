class Solution {
public:
// player 1 score track via p1 and player 2 score track via p2 and see whose turn to pick 
// picking add score to p1 and remove from p2 
    int solve(int p1,int p2,int turn,vector<int>& nums,vector<vector<vector<int>>>&dp){
        if(p1>p2) return 0; 
        if(dp[p1][p2][turn]!=-1) return dp[p1][p2][turn];
        if(turn){
            return dp[p1][p2][turn] = max(nums[p1]+solve(p1+1,p2,0,nums,dp),nums[p2]+solve(p1,p2-1,0,nums,dp));
        }
        return dp[p1][p2][turn] = min(-nums[p1]+solve(p1+1,p2,1,nums,dp),-nums[p2]+solve(p1,p2-1,1,nums,dp));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1))) ;
        int ans = solve(0,n-1,1,nums,dp);
        return ans>=0; 
    }
};
