class Solution {
public:
    const int mod = 1e9+7; 
    int solve(int ind,int steps,int arrLen,vector<vector<int>>&dp){
        if(ind>=arrLen || ind<0){
            return 0;
        }
        if(steps==0){
            return ind==0;
        }
        if(dp[ind][steps]!=-1) {
            return dp[ind][steps];
        }
        long R = solve(ind+1,steps-1,arrLen,dp)%mod ; 
        long L = solve(ind-1,steps-1,arrLen,dp)%mod ; 
        long S = solve(ind,steps-1,arrLen,dp)%mod ; 
    return dp[ind][steps] = (R+L+S)%mod ;
    }
    int numWays(int steps, int arrLen) {
       // WHY THOSE WHO CAN'T  REMEMBER THE PAST ARE CONDEMNED TO REMEMBER IT :) 
        int move = min(steps/2+1,arrLen);
        //OBSERVATION :- WE CAN MOVE STEPS/2+1 TIMES MAX RIGHT OR LEFT 
        // JUST IGNORING ARRLEN FACT 
        vector<vector<int>>dp(move,vector<int>(steps+1,-1));
        return solve(0,steps,move,dp);
    }
};
