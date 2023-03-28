class Solution {
public: //Approach-1 Recursion
    int solve(int ind, vector<int>& days, vector<int>& costs,int n) {
        if(ind >= n)  return 0;
   
        int pos7 = 1e9, pos30 = 1e9;
        for(int i = ind+1; i < n; i++) {
            if(days[i] >= days[ind] + 7) {
                pos7 = i; 
                break;
            }
        }
        for(int i = ind+1; i < n; i++) {
            if(days[i] >= days[ind] + 30) {
                pos30 = i; 
                break;
            }
        }
        int way1 = costs[0] + solve(ind+1, days, costs,n);
        int way2 = costs[1] + solve(pos7, days, costs,n);
        int way3 = costs[2] + solve(pos30, days, costs,n);
        
        return min({way1, way2, way3});
    }
    //Approach-2 Memoization
        int solve2(int ind, vector<int>& days, vector<int>& costs,vector<int>&dp,int n) {
        if(ind >= n)  return 0;
   
        int pos7 = 1e9, pos30 = 1e9; 
        if(dp[ind]!=-1) return dp[ind] ;
        for(int i = ind+1; i < n; i++) {
            if(days[i] >= days[ind] + 7) {
                pos7 = i; 
                break;
            }
        }
        for(int i = ind+1; i < n; i++) {
            if(days[i] >= days[ind] + 30) {
                pos30 = i; 
                break;
            }
        }
        int way1 = costs[0] + solve2(ind+1, days, costs,dp,n);
        int way2 = costs[1] + solve2(pos7, days, costs,dp,n);
        int way3 = costs[2] + solve2(pos30, days, costs,dp,n);
        
        return dp[ind] =  min({way1, way2, way3});
    }  
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
     //   return solve(0, days,costs,n); //Approach-1 Recursion
        return solve2(0, days,costs,dp,n); //Approach-2 Memoization
    }
};
