class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1;
        
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1;
        double sum = 1  , result=0;
        
        for(int i = 1; i <= n; i++) {
            dp[i]+= (sum*1.0)/maxPts;
            if(i - maxPts >= 0) sum-=dp[i - maxPts];
            if(i < k) sum += dp[i];
        }
        for(int i = k; i <= n; i++) result+= dp[i];
        return result;
    }
};
