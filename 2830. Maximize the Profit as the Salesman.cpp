class Solution {
public:
    int bs(int val,int low,vector<vector<int>>& offers){
        int high = offers.size()-1  ; 
        while(low<=high){
            int mid = low + (high-low)/2 ; 
            if(offers[mid][0]>val){
                high=mid-1;
            }
            else low=mid+1;
        }
    return low;
    }
    int solve(int ind,vector<vector<int>>& offers,vector<int>&dp){
        int m = offers.size() ; 
        if(ind==m) return 0;
        if(dp[ind]!=-1) return dp[ind] ; 
        int notTake=solve(ind+1,offers,dp) ; 
        int nextPos = bs(offers[ind][1],ind,offers); 
        int take = offers[ind][2] + solve(nextPos,offers,dp);
        return dp[ind]=max(take,notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //DP+BS 
        int m = offers.size() ; 
        vector<int>dp(m,-1); 
        sort(offers.begin(),offers.end());
        return solve(0,offers,dp);
    }
};
