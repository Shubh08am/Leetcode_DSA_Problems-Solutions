class Solution {
public: 
    //Approach-1 Recursion
    int solve(int ind,int time,vector<int>& satisfaction){
        int n=satisfaction.size() ; 
        if(ind>=n) return 0;
        int pick = satisfaction[ind]*time + solve(ind+1,time+1,satisfaction) ;
        int notPick = solve(ind+1,time,satisfaction) ; 
    //    cout<<ind<<" "<<pick<<" "<<notPick<<"\n";
        return max(pick,notPick) ;
    }
    //Approach-2 Memoization
    int solve2(int ind,int time,vector<int>& satisfaction,vector<vector<int>>&dp){
        int n=satisfaction.size() ; 
        if(ind>=n) return 0; 
        
        if(dp[ind][time]!=-1) return dp[ind][time];

        int pick = satisfaction[ind]*time + solve2(ind+1,time+1,satisfaction,dp) ;
        int notPick = solve2(ind+1,time,satisfaction,dp) ; 
    //    cout<<ind<<" "<<pick<<" "<<notPick<<"\n";
        return dp[ind][time] = max(pick,notPick) ;
    }
     //Approach-4 Tabulation
    int Tabulation(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int time=i;time>=0;time--){

                int pick=satisfaction[i]*(time+1) +dp[i+1][time+1];
                int notPick=dp[i+1][time];

                dp[i][time]=max(pick,notPick);
            }
        }
        return dp[0][0];
    }
     //Approach-5 Tabulation
    int TabulationSpaceOptimization(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<int>prev(n+1),curr(n+1);
        
        for(int i=n-1;i>=0;i--){
            for(int time=i;time>=0;time--){

                int pick=satisfaction[i]*(time+1) +prev[time+1];
                int notPick=prev[time];

                curr[time]=max(pick,notPick);
            }
            prev=curr;
        }
        return prev[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
    //Approach-3 greedy appraoch
    /*
        //greedy appraoch :- Assign max positive number later task and least number earlier task  
        sort(satisfaction.begin(),satisfaction.end(),[&](auto&a , auto&b){return a>b;}) ; //descending order using comparator
       // for(auto&val:satisfaction) cout<<val<<" "; 
       int time=0 , currDish=0 , n=satisfaction.size() ; 
       for(int i=0;i<n-1;i++){
           satisfaction[i+1]+=satisfaction[i];
       }
       for(int i=0;i<satisfaction.size();i++){
           currDish+=satisfaction[i];
           time=max(time,currDish);
       }
        return time;
    */
   int n=satisfaction.size() ; 
   sort(satisfaction.begin(),satisfaction.end()) ; 
  //  return solve(0,1,satisfaction); //Approach-1 Recursion
  //   vector<vector<int>>dp(n,vector<int>(n+1,-1)); //2d as two states changing one for time and one for value pos
   //  return solve2(0,1,satisfaction,dp);  //Approach-2 Memoization 
  // return Tabulation(satisfaction) ;  //Approach-4 Tabulation 
return TabulationSpaceOptimization(satisfaction) ;
    }
};
