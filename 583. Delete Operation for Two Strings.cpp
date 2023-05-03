class Solution {
public: 
   //Approach-1 Recursion Time Complexity: O(2^N*2^M) Space Complexity: O(N+M)
    int solve(int i,int j,string&word1,string&word2){

        if(j<0) return i+1; //word2 traversed completely --> delete remainig character from word1 
        if(i<0) return j+1;

        //match case 
        if(word1[i]==word2[j]){
            return solve(i-1,j-1,word1,word2);
        }
        else{
            return 1+min(solve(i-1,j,word1,word2) , solve(i,j-1,word1,word2)) ;
        }
    }
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    int solve2(int i,int j,string&word1,string&word2,vector<vector<int>>&dp){

        if(j<0) return i+1; //word2 traversed completely --> delete remainig character from word1 
        if(i<0) return j+1;
          
        if(dp[i][j]!=-1) return dp[i][j];

        //match case 
        if(word1[i]==word2[j]){
            return dp[i][j]=solve2(i-1,j-1,word1,word2,dp);
        }
        else{
            return dp[i][j]=1+min(solve2(i-1,j,word1,word2,dp) , solve2(i,j-1,word1,word2,dp)) ;
        }
    }
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int solve3(int i,int j,string&word1,string&word2,vector<vector<int>>&dp){

        if(j==0) return i; //word2 traversed completely --> delete remainig character from word1 
        if(i==0) return j;
          
        if(dp[i][j]!=-1) return dp[i][j];

        //match case 
        if(word1[i-1]==word2[j-1]){
            return dp[i][j]=solve3(i-1,j-1,word1,word2,dp);
        }
        else{
            return dp[i][j]=1+min(solve3(i-1,j,word1,word2,dp) , solve3(i,j-1,word1,word2,dp)) ;
        }
    }
     //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulation(string word1,string word2){
          int n=word1.size() , m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j ; 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
 //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
     int tabulationWithSpaceOptimization(string word1,string word2){
          int n=word1.size() , m=word2.size();
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int j=0;j<=m;j++) prev[j] = j ; //for i=0 -> j varies from 0 to m

        for(int i=1;i<=n;i++){
            curr[0]=i; //for j=0 -> i varies from 0 to n
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                   curr[j] = prev[j-1];
                }
                else{
                    curr[j]=1+min(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        //EDIT DISTANCE QUESTION PATTERN 
        int n=word1.size() , m=word2.size();
       // return solve(n-1,m-1,word1,word2); //Approach-1 Recursion
       
       // vector<vector<int>>dp(n,vector<int>(m,-1));
      //  return solve2(n-1,m-1,word1,word2,dp) ; //Approach-2 Memoization

     //   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     //   return solve3(n,m,word1,word2,dp) ; //Approach-2 Memoization 

     //   return tabulation(word1,word2); //Approach-3 Tabulation 
         return tabulationWithSpaceOptimization(word1,word2); //Approach-4 tabulation With Space Optimization 
    }
};
