class Solution {
public:
    int solve(int ind,int m,vector<int> &piles,vector<vector<int>> &dp){
        int n = piles.size();

        if(ind >= piles.size()) return 0;

        if(dp[ind][m]!=-1) return dp[ind][m];

        int ans = -1e9;
        int score = 0;

        for(int i = ind;i<(ind + 2*m) && i<n ;i++){
            score += piles[i];
            ans = max(ans,score - solve(i+1,max((i+1 - ind),m),piles,dp));
        }

        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int ans = (sum + solve(0,1,piles,dp))/2;

        return ans;
    }
};
