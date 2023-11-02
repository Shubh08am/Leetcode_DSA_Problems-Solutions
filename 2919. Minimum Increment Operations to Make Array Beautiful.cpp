#define ll long long
class Solution {
public:
    ll max(ll a,ll b){
        return a>=b?a:b;
    }
    ll solve(ll ind,vector<int>& nums, int k,vector<ll>&dp) {
         int n=nums.size();
         if(ind>n-3) return 0;
         ll &val = dp[ind];
         if(val!=-1) return val;
         ll first = max(0,k-nums[ind]) + solve(ind+1,nums,k,dp) ;
         ll second = max(0,k-nums[ind+1]) + solve(ind+2,nums,k,dp) ;
         ll third = max(0,k-nums[ind+2]) + solve(ind+3,nums,k,dp) ;
        return val = min({first,second,third});
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        ll ans = 1e18,n=nums.size();
        vector<ll>dp(n+3,-1);
        ans=solve(0,nums,k,dp);
        return ans;
    }
};
