class Solution {
public:
 //Approach-1 Recursion Time Complexity: O(2^N*2^M) Space Complexity: O(N+M)
    int solve(int i,int j,string&s1,string&s2){

        if(j<0) { //word2 traversed completely --> delete remainig character from word1 
            int ans=0;
            for(int k=0;k<=i;k++) ans+=(int)s1[k];
          return ans; 
        }
        if(i<0) { //word1 traversed completely --> delete remainig character from word2 
            int ans=0;
            for(int k=0;k<=j;k++) ans+=(int)s2[k];
          return ans; 
        }

        //match case 
        if(s1[i]==s2[j]){
            return solve(i-1,j-1,s1,s2);
        }
        else{
         //   cout<< (int)s1[i] + solve(i-1,j,s1,s2)  << " "<< (int)s2[j] +solve(i,j-1,s1,s2) <<"\n";
            return min((int)s1[i] + solve(i-1,j,s1,s2) , (int)s2[j] +solve(i,j-1,s1,s2)) ;
        }
    }
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
   int solve2(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){

        if(j<0) { //word2 traversed completely --> delete remainig character from word1 
            int ans=0;
            for(int k=0;k<=i;k++) ans+=(int)s1[k];
          return ans; 
        }
        if(i<0) { //word1 traversed completely --> delete remainig character from word2 
            int ans=0;
            for(int k=0;k<=j;k++) ans+=(int)s2[k];
          return ans; 
        }
        
        if(dp[i][j]!=-1) return dp[i][j] ;
        //match case 
        if(s1[i]==s2[j]){
            return dp[i][j] = solve2(i-1,j-1,s1,s2,dp);
        }
        else{
         //   cout<< (int)s1[i] + solve(i-1,j,s1,s2)  << " "<< (int)s2[j] +solve(i,j-1,s1,s2) <<"\n";
            return dp[i][j] = min((int)s1[i] + solve2(i-1,j,s1,s2,dp) , (int)s2[j] +solve2(i,j-1,s1,s2,dp)) ;
        }
    }
     //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulation(string &s1,string &s2){
          int n=s1.size() , m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) dp[i][0] = dp[i-1][0] + (int)s1[i-1];
        for(int j=1;j<=m;j++) dp[0][j]=dp[0][j-1] + (int)s2[j-1]; 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min((int)s1[i-1]+dp[i-1][j],(int)s2[j-1]+dp[i][j-1]);
                }
            }
        }
     //   for(int i=0;i<=n;i++){
     //    for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    //   }
        return dp[n][m];
    }
//Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulationWithSpaceOptimization(string &s1,string &s2){
          int n=s1.size() , m=s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int j=1;j<=m;j++) prev[j]=prev[j-1] + (int)s2[j-1]; 

        for(int i=1;i<=n;i++){
            curr[0]=prev[0] + (int)s1[i-1]; 
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                   curr[j] = prev[j-1];
                }
                else{
                    curr[j]=min((int)s1[i-1]+prev[j],(int)s2[j-1]+curr[j-1]);
                }
            }
            prev=curr;
        }
        for(int j=0;j<=m;j++) cout<<prev[j]<<" ";
        return prev[m];
    }
    int minimumDeleteSum(string s1, string s2) {
         //EDIT DISTANCE QUESTION PATTERN 
        int n=s1.size() , m=s2.size();
      //  return solve(n-1,m-1,s1,s2); //Approach-1 Recursion
    
       vector<vector<int>>dp(n,vector<int>(m,-1));
       int ans =  solve2(n-1,m-1,s1,s2,dp); //Approach-2 Memoization
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
   //    }
      // return ans;
     //  cout<<"\n";
     
     //   return tabulation(s1,s2); //Approach-3 Tabulation

    return tabulationWithSpaceOptimization(s1,s2); //Approach-4 tabulation With Space Optimization 
    }
};
