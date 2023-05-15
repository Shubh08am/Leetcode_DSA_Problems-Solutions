class Solution {
public:
   //Approach-1 Recursion Time Complexity: EXPONENTIAL   
    int solve(int i,int j,vector<int>& cuts){
        if(i>j) return 0 ; 

        int minCost=INT_MAX;
        // TRY OUT ALL PARTITION
        for(int ind=i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts) + solve(ind+1,j,cuts);
            minCost=min(minCost,cost);
        }
        return minCost;
    }
   //Approach-2 Memoization :- Time Complexity: O(N*N*N) Space Complexity: O(N*N) + O(N) [ASS]
   //Reason for TC: There are 2 variables i and j, therefore, N*N states and we explicitly run a loop
   // inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

    int solve2(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j] ; 

        // TRY OUT ALL PARTITION 
        int minCost = INT_MAX; 
        for(int ind=i;ind<=j;ind++){
            int score = cuts[j+1]-cuts[i-1]+solve2(i,ind-1,cuts,dp)+solve2(ind+1,j,cuts,dp);
            minCost=min(minCost,score); //TAKE MIN ONE
          }
          return dp[i][j]=minCost;
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*N*N) Space Complexity: O(N*N)
    //Reason for TC: There are 2 variables i and j, therefore, N*N states and we explicitly run 
    //a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
    int tabulation(int n , vector<int>&cuts){
        int m=cuts.size() ; 
        cuts.insert(cuts.end(),n) ; 
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(m+2,vector<int>(m+2,0));

        //BASE CASE :- i>j -> return 0 already covered as dp initialized to 0 
     
           
        for(int i=m;i>=1;i--){
            for(int j=i;j<=m;j++){
                //  if(i>j) continue ; // if j starts from 1 include it //BASE CASE 

                //COPY RECURRENCE 
                int minCost=INT_MAX;
                // TRY OUT ALL PARTITION
                for(int ind=i;ind<=j;ind++){
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1] + dp[ind+1][j];
                    minCost=min(minCost,cost);
                }
                dp[i][j]= minCost;
            }
        }
    return dp[1][m];
    }

    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        //for Recursion and Memoization Uncomment three lines push one and sort 
     //   cuts.push_back(n);  
     //   cuts.insert(cuts.begin(),0);

       //SO THAT SUB-PROBLEMS CAN BE SOLVED INDEPENDENTLY
      //  sort(cuts.begin(),cuts.end());

     //   return solve(1,m,cuts);  //Approach-1 Recursion
        
     //   vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
     //   return solve2(1,m,cuts,dp); //Approach-2 Memoization

          return tabulation(n,cuts); //Approach-3 Tabulation
    }
};
