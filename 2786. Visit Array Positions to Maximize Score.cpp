// cry cry cry 
class Solution {
public:
    long long solve(int ind,vector<int>& nums, int x,vector<vector<long long>>&dp,int parity){
        if(ind==nums.size()) return 0;
        
        if(dp[ind][parity]!=-1) return dp[ind][parity];
         long long notTake = solve(ind+1,nums,x,dp,parity) ; 
        long long take = 0 ; 
        if((parity%2==0&&nums[ind]%2==0 )|| (parity%2!=0&&nums[ind]%2!=0)){
           take=nums[ind]+ solve(ind+1,nums,x,dp,nums[ind]%2) ; 
        }
        else if((parity%2==0&&nums[ind]%2!=0) || (parity%2!=0&&nums[ind]%2==0) ){
           take=nums[ind]+ solve(ind+1,nums,x,dp,nums[ind]%2) - x ; 
        }
     return dp[ind][parity] = max(take,notTake);   
    }
    long long maxScore(vector<int>& nums, int x) {
       long long ans = 0 , n = nums.size(); 
       vector<vector<long long>>dp(n,vector<long long>(2,-1));
       return solve(0,nums,x,dp,nums[0]%2);
    }
};
