class Solution {
public:
     //Approach-1 Recursion Time Complexity: EXPONENTIAL   
    int solve(int i , int j , vector<int>&arr){
        if(i==j) return 0 ; //single matrix no multiplication operation 
        
        //try out all partition 
        int minCost = INT_MAX;
        for(int ind=i;ind<j;ind++){
            int cost = arr[i-1]*arr[ind]*arr[j] + solve(i,ind,arr) + solve(ind+1,j,arr);
            
            minCost=min(minCost,cost);
        }
        return minCost;
    }
    
    //Approach-2 Memoization :- Time Complexity: O(N*N*N) Space Complexity: O(N*N) + O(N) [ASS]
    //Reason for TC: There are N*N states and we explicitly run a loop inside the
    //function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
    
    int solve2(int i , int j , vector<int>&arr,vector<vector<int>>&dp){
        if(i==j) return 0 ; //single matrix no multiplication operation 
        
        if(dp[i][j]!=-1) return dp[i][j] ; 
        
        //try out all partition  from i to j-1[included]
        int minCost = INT_MAX;
        for(int ind=i;ind<j;ind++){
            int cost = arr[i-1]*arr[ind]*arr[j] + solve2(i,ind,arr,dp) + solve2(ind+1,j,arr,dp);
            
            minCost=min(minCost,cost);
        }
        return dp[i][j]  = minCost;
    }
      //Approach-3 Tabulation :- Time Complexity: O(N*N*N) Space Complexity: O(N*N)
    int tabulation(int n , vector<int>&arr){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        //BASE CASE :- i==j return 0
        for(int i=1;i<n;i++){
            dp[i][i]=0;
        }
        
        //NOW, IN RECURSION CALL i -> 1 to n-1 && j=n-1 to 1 
        // SO, IN TABULATION CALL  i -> n-1 to 1 && j=1 to n-1 
        
        //BUT, i is always on left of j . thus, j starts from j->i+1 to n-1 
        
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int minCost = INT_MAX; 
                
                for(int k=i;k<j;k++){
                    int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    minCost=min(minCost,cost);
                }
                dp[i][j]  = minCost;
            }
        }
    return dp[1][n-1]; //AS RECURSION CALL FROM (1,n-1)
    }
    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
     //   return solve(1,n-1,arr) ;  //Approach-1 Recursion
     
     //    vector<vector<int>>dp(n,vector<int>(n,-1));
     //    return solve2(1,n-1,arr,dp) ;  //Approach-2 Memoization
       
         return tabulation(n,arr); //Approach-3 Tabulation
    }
};
