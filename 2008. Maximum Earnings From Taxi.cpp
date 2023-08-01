class Solution {
public:
    long long bs(long long low,long long val,vector<vector<int>>& rides,int n){
        long long high = n-1; 
        while(low<=high){
            int mid = low+(high-low)/2; 
            if(rides[mid][0]>=val){
                high=mid-1;
            }
            else low=mid+1;
        }
    return low;
    }
    long long solve(int ind,int n,vector<vector<int>>& rides,vector<long long>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long notTake=solve(ind+1,n,rides,dp);
        long long pos = bs(ind,rides[ind][1],rides,n) ; 
        long long take = rides[ind][1]-rides[ind][0]+rides[ind][2]+solve(pos,n,rides,dp) ; 
        return dp[ind] = max(take,notTake); 
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // DP+BS 
        sort(rides.begin(),rides.end()) ; 
        vector<long long>dp(rides.size()+1,-1);
        return solve(0,rides.size(),rides,dp);
    }
};
