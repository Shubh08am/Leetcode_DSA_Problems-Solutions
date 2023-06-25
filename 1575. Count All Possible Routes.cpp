const int mod = 1e9+7;
class Solution {
public:
   //T.C -> O(N*NFUEL) S.C->O(N*FUEL)+O(N)
    int solve(int start, int finish, int fuel,vector<int>& locations,vector<vector<int>>&dp){
        int n = locations.size() ; 
        int routes=0;

        if(fuel<=0){
            if(start==finish) return 1;
            else return 0;
        }

        if(start==finish){
            routes++;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];

        //EXPLORE ALL PATH 
        for(int path=0;path<n;path++){
            //CAN'T MOVE TO SAME CITY FROM SAME CITY
            if(start==path) continue;
            //MOVING FROM START[KEEP UPDATING] TO NEW CITY I.E PATH
            int newFuel = fuel - abs(locations[path]-locations[start]) ; 
            if(newFuel>=0) routes=(routes+solve(path,finish,newFuel,locations,dp))%mod ;
        }

        return dp[start][fuel]=routes ; 
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size() ; 
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return solve(start,finish,fuel,locations,dp);
    }
};
