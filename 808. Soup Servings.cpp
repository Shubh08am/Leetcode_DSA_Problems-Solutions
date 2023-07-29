class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;
    double solve(int  A, int B){
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0 && B>0) return 1;
        if (A>0 && B<= 0) return 0;
        if (dp[A].count(B)) return dp[A][B];
        return dp[A][B] = (solve(A - 100, B) + solve(A - 75, B - 25) +solve(A - 50, B - 50) + solve(A - 25, B - 75)) / 4.0;
    }

    double soupServings(int n) {
        if(n>5000) return 1;
        return solve(n,n);
    }
};
