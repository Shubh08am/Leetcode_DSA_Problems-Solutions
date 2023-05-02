class Solution {
public:
     //Approach-1 Recursion Time Complexity: O(2^N*2^M) Space Complexity: O(N+M)
    int solve(int i,int j,string s,string t){
        if(j<0) return 1;
        if(i<0) return 0;

        //match case 
        if(s[i]==t[j]){
            //two case :- Take both 
            return solve(i-1,j-1,s,t) + solve(i-1,j,s,t) ; 
        }
        if(s[i]!=t[j]){
            return solve(i-1,j,s,t);
        }
    return 0;
    }
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    int solve2(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        //match case 
        if(s[i]==t[j]){
            //two case :- Take both 
            return dp[i][j] = solve2(i-1,j-1,s,t,dp) + solve2(i-1,j,s,t,dp) ; 
        }
        else{
            return dp[i][j] = solve2(i-1,j,s,t,dp);
        }
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    int tabulation(string s,string t){
         int n=s.size(),m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0)); 
        
        // Base Case :- if(j<0) return 1 ; --> i varies from 0 to n 
        for(int i=0;i<=n;i++){
            dp[i][0] = 1 ; 
        }
        // Base Case :- if(i<0) return 0 ; --> j varies from 1 to m --> as dp[0][0]=1 from up base case
        for(int j=1;j<=m;j++){
            dp[0][j] = 0 ; 
        }
         //for states 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    unsigned subsequence = dp[i-1][j-1]+dp[i-1][j] ;
                    dp[i][j]=subsequence;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    return dp[n][m];
    }
    //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    int tabulationWithSpaceOptimization(string s,string t){
         int n=s.size(),m=t.size();
        vector<long long>prev(m+1,0),curr(m+1,0); 
        
            curr[0]=prev[0] = 1 ; 
        
         //for states 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    unsigned subsequence = prev[j-1]+prev[j] ;
                    curr[j]=subsequence;
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
     //   for(auto i : prev) cout<<i<<" ";
    return prev[m];
    }
    //Approach-5 tabulation With Space Optimization[[Using Single Row]] :- Time Complexity: O(N*M) Space Complexity: O(M)
      int tabulationWithSpaceOptimization2(string s,string t){
         int n=s.size(),m=t.size();
        vector<long long>prev(m+1,0); 
        
        prev[0] = 1 ; 
        
         //for states 
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    unsigned subsequence = prev[j-1]+prev[j] ;
                    prev[j]=subsequence;
                }
           }
        }
     //   for(auto i : prev) cout<<i<<" ";
    return prev[m];
    }
    int numDistinct(string s, string t) {
        /*
        Base Case- 
        case 1 :- If all character of t searched return 1 as subsequence possible 
        case 2 :-  If all character of s searched return 0 as subsequence not possible 

       When characters matches :- 
       case 1 :- both pointers reduced on both s & t 
       case 2 : on s pointer reduced and stayed on t

       When characters doesn't matches :-
       case 1 :- on s pointer reduced and stayed on t
        */
        int n=s.size(),m=t.size();
        // return solve(n-1,m-1,s,t); //Approach-1 Recursion
        
     //   vector<vector<int>>dp(n,vector<int>(m,-1));
     //   return solve2(n-1,m-1,s,t,dp); //Approach-2 Memoization

    // return tabulation(s,t); //Approach-3 tabulation

    //  return tabulationWithSpaceOptimization(s,t); //Approach-4 tabulation With Space Optimization [Using Two Array]

     return tabulationWithSpaceOptimization2(s,t); //Approach-5 tabulation With Space Optimization [Using Single Array]
     }
};
