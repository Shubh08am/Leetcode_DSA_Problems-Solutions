class Solution {
public:
    bool isAllStars(string & p, int i) {
       for (int j = 0; j <= i; j++) {
         if (p[j] != '*')  return false;
        }
    return true;
   } 
     //Approach-1 Recursion Time Complexity: EXPONENTIAL Space Complexity: O(N+M)
    bool solve(int i,int j,string&s,string&p){
        int n=s.size() , m=p.size() ; 

        if(i<0 && j<0) return 1;
        if(j<0 && i>=0) return 0; //p exhausted
         if(i<0 && j>=0) { //s exhausted
         //ALL * matches with empty i.e "" in s 
            //   int cnt= count(p.begin(),p.begin()+j+1,'*');
            //   return cnt==j+1 ; 
            return isAllStars(p,j) ; //or use this 
        }

        if(s[i]==p[j]) return solve(i-1,j-1,s,p) ; 
        if(p[j]=='?')  return solve(i-1,j-1,s,p) ; 
        if(s[i]!=p[j] && p[j]!='*' && p[j]!='?') return 0;
        if(p[j]=='*') return solve(i-1,j,s,p) | solve(i,j-1,s,p);
        return 0; 
    }
   //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
     bool solve2(int i,int j,string&s,string&p,vector<vector<int>>&dp){
        int n=s.size() , m=p.size() ; 

        if(i<0 && j<0) return 1;
        if(j<0 && i>=0) return 0;
         if(i<0 && j>=0) {
             // int cnt= count(p.begin(),p.begin()+j+1,'*');
            //   return cnt==j+1 ; 
             return isAllStars(p,j) ; //or use this 
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j]) return dp[i][j]=solve2(i-1,j-1,s,p,dp) ; 
        if(p[j]=='?')  return dp[i][j]=solve2(i-1,j-1,s,p,dp) ; 
        if(s[i]!=p[j] && p[j]!='*' && p[j]!='?')  return dp[i][j]=0;
        if(p[j]=='*') return dp[i][j]=solve2(i-1,j,s,p,dp) | solve2(i,j-1,s,p,dp);
        return dp[i][j]=0;
        }

    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
     bool solve3(int i,int j,string&s,string&p,vector<vector<int>>&dp){
        int n=s.size() , m=p.size() ; 

        if(i==0 && j==0) return 1;
        if(j==0 && i>0) return 0;
         if(i==0 && j>0) {
            //  int cnt= count(p.begin(),p.begin()+j,'*');
            //   return cnt==j ; 
            //or use this
           for (int j = 1; j <= i; j++) {
              if (p[j-1] != '*')  return false;
             }
        return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1]) return dp[i][j]=solve3(i-1,j-1,s,p,dp) ; 
        if(p[j-1]=='?')  return dp[i][j]=solve3(i-1,j-1,s,p,dp) ; 
        if(s[i-1]!=p[j-1] && p[j-1]!='*' && p[j-1]!='?')  return dp[i][j]=0;
        if(p[j-1]=='*') return dp[i][j]=solve3(i-1,j,s,p,dp) | solve3(i,j-1,s,p,dp);
        return dp[i][j]=0;
        }
    //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulation(string &s,string &p){
        int n=s.size() , m=p.size() ;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        
        //BASE CASE
        dp[0][0] = true;
        for(int i=1;i<=n;i++) dp[i][0] = false; 
        for(int j=1;j<=m;j++){
            bool  flag = true; 
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

     //CHANGING PARAMETER 
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             //MATCH 
             if(s[i-1]==p[j-1] || p[j-1]=='?') {
                 dp[i][j] = dp[i-1][j-1];
             }
             //* CASE
            else if(p[j-1]=='*'){
                // dp[i][j-1] -> EMPTY CASE 
                //dp[i-1][j]  -> MATCH CASE OF *
                 dp[i][j] = dp[i-1][j] | dp[i][j-1];
             }
             else dp[i][j] = false;
         }
     }
    return dp[n][m];
    }
     int tabulation2(string &s,string &p){
        int n=s.size() , m=p.size() ;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        
        //BASE CASE
        dp[0][0] = true;
        for(int i=1;i<=n;i++) dp[i][0] = false; 
        for(int j=1;j<=m;j++){
            bool vis = true;
             for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    dp[0][j]=false;
                    vis = false;
                 }
             }
             if(vis) dp[0][j] = true;
         }

     //CHANGING PARAMETER 
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             //MATCH 
             if(s[i-1]==p[j-1] || p[j-1]=='?') {
                 dp[i][j] = dp[i-1][j-1];
             }
             //* CASE
            else if(p[j-1]=='*'){
                // dp[i][j-1] -> EMPTY CASE 
                //dp[i-1][j]  -> MATCH CASE OF *
                 dp[i][j] = dp[i-1][j] | dp[i][j-1];
             }
             else dp[i][j] = false;
         }
     }
    return dp[n][m];
    }
    //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
     int tabulationWithSpaceOptimization(string &s,string &p){
        int n=s.size() , m=p.size() ;
         vector<bool>prev(m+1,false),curr(m+1,false);
        
        //BASE CASE
        prev[0] = true;

        for(int j=1;j<=m;j++){
            bool vis = true;
             for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    prev[j]=false;
                    vis = false;
                 }
             }
             if(vis) prev[j] = true;
         }

     //CHANGING PARAMETER 
     for(int i=1;i<=n;i++){
         curr[0] = false;
         for(int j=1;j<=m;j++){
             //MATCH 
             if(s[i-1]==p[j-1] || p[j-1]=='?') {
                 curr[j] = prev[j-1];
             }
             //* CASE
            else if(p[j-1]=='*'){
                // curr[j-1] -> EMPTY CASE 
                //prev[j]  -> MATCH CASE OF *
                 curr[j] = prev[j] | curr[j-1];
             }
             else curr[j] = false;
         }
         prev=curr;
     }
    return prev[m];
    }

     int tabulationWithSpaceOptimization2(string &s,string &p){
        int n=s.size() , m=p.size() ;
         vector<bool>prev(m+1,false),curr(m+1,false);
        
        //BASE CASE
        prev[0] = true;

        for(int j=1;j<=m;j++){
             bool  flag = true; 
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;
         }

     //CHANGING PARAMETER 
     for(int i=1;i<=n;i++){
         curr[0] = false;
         for(int j=1;j<=m;j++){
             //MATCH 
             if(s[i-1]==p[j-1] || p[j-1]=='?') {
                 curr[j] = prev[j-1];
             }
             //* CASE
            else if(p[j-1]=='*'){
                // curr[j-1] -> EMPTY CASE 
                //prev[j]  -> MATCH CASE OF *
                 curr[j] = prev[j] | curr[j-1];
             }
             else curr[j] = false;
         }
         prev=curr;
     }
    return prev[m];
    }

    int tabulationWithSpaceOptimization3(string &s,string &p){
 // https://leetcode.com/problems/wildcard-matching/solutions/2489651/c-recursion-memoization-tabulation-spaceoptimization/?orderBy=most_votes&page=6

          int m=s.size() , n=p.size() ;
         vector<bool>prev(m+1,false),curr(m+1,false);
        
        //BASE CASE
        prev[0] = true;

     //CHANGING PARAMETER 
     for(int i=1;i<=n;i++){
            bool  flag = true; 
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            curr[0]=flag;   
         for(int j=1;j<=m;j++){
             //MATCH 
             if(p[i-1]==s[j-1] || p[i-1]=='?') {
                 curr[j] = prev[j-1];
             }
             //* CASE
            else if(p[i-1]=='*'){
                // curr[j-1] -> EMPTY CASE 
                //prev[j]  -> MATCH CASE OF *
                 curr[j] = prev[j] | curr[j-1];
             }
             else curr[j] = false;
         }
         prev=curr;
     }
    return prev[m];
     }

    bool isMatch(string s, string p) {
        /* i points on s j will be pointing on p 
        if charcter matches reduced both i&j 
        if ? occurs in p than also reduced both i&j 
        if charcter doesn't matches and no * is there and ? --> return false 
        if * occurs in p --> go to previous position in p and than try to match that character within s 
        with first * match s.size() - p.size() + 1 character  

        NOT POSSIBLE CASE :- 
        if p size is more than s with * case handled
        */
        int n=s.size() , m=p.size() ; 
       // return solve(n-1,m-1,s,p);  //Approach-1 Recursion

      //  vector<vector<int>>dp(n,vector<int>(m,-1));
      //  return solve2(n-1,m-1,s,p,dp); //Approach-2 Memoization

    //  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //  return solve3(n,m,s,p,dp); //Approach-2 Memoization

    //   return tabulation(s,p);   //Approach-3 Tabulation 

    //     return tabulation2(s,p);   //Approach-3 Tabulation 

    //     return tabulationWithSpaceOptimization(s,p);  //Approach-4 tabulation With Space Optimization

    //     return tabulationWithSpaceOptimization2(s,p); 

    return tabulationWithSpaceOptimization3(s,p); 
    }
};
