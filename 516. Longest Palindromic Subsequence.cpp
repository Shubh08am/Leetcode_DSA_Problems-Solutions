class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(2^N*2^M) Space Complexity: O(N+M)
    //Recursion call from (0,0)
      int solve(int ind1 , int ind2 , int n , int m , string &text1, string &text2){
        //base case 
        if(ind1>=n || ind2>=m) return 0;

        //match 
        if(text1[ind1]==text2[ind2]){
            int match = 1 +  solve(ind1+1,ind2+1,n,m,text1,text2) ; 
            return match;
        }

        //not-match 
        if(text1[ind1]!=text2[ind2]){ 
            //two calls
            int pos1 =  solve(ind1+1,ind2,n,m,text1,text2) ; 
            int pos2 =  solve(ind1,ind2+1,n,m,text1,text2) ; 
            int notMatch = max(pos1,pos2); //take max of both
            return notMatch;
        } 
    return 0;
    }  
    //Approach-1 Recursion Time Complexity: O(2^N*2^M) Space Complexity: O(N+M)
    //Recursion call from (n-1,m-1)
      int solve4(int ind1 , int ind2 , int n , int m , string &text1, string &text2){
        //base case 
        if(ind1<0 || ind2<0) return 0;

        //match 
        if(text1[ind1]==text2[ind2]) return  1 +  solve4(ind1-1,ind2-1,n,m,text1,text2)  ;
        
        //not-match 
        return max(solve4(ind1-1,ind2,n,m,text1,text2) , solve4(ind1,ind2-1,n,m,text1,text2));
      } 
    //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    ////Recursion call from (0,0)
    int solve2(int ind1 , int ind2 , int n , int m , string &text1, string &text2,vector<vector<int>>&dp){

        if(ind1>=n || ind2>=m) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //match 
        if(text1[ind1]==text2[ind2]){
            int match = 1 +  solve2(ind1+1,ind2+1,n,m,text1,text2,dp) ; 
            return dp[ind1][ind2]= match;
        }
        //not-match 
        if(text1[ind1]!=text2[ind2]){ 
            //two calls
            int pos1 =  solve2(ind1+1,ind2,n,m,text1,text2,dp) ; 
            int pos2 =  solve2(ind1,ind2+1,n,m,text1,text2,dp) ; 
            int notMatch = max(pos1,pos2); 
            return dp[ind1][ind2]=notMatch;
        } 
    return 0;
    }

     //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
     //Recursion call from (n-1,m-1)
      int solve5(int ind1 , int ind2 , int n , int m , string &text1, string &text2,vector<vector<int>>&dp){
        //base case 
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //match 
        if(text1[ind1]==text2[ind2]) return dp[ind1][ind2]= 1 +  solve5(ind1-1,ind2-1,n,m,text1,text2,dp)  ;
        
        //not-match 
        return dp[ind1][ind2]=max(solve5(ind1-1,ind2,n,m,text1,text2,dp) , solve5(ind1,ind2-1,n,m,text1,text2,dp));
      } 
   //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    //Recursion call from (-1,-1) -> After Left shifting of index(index=-1 (left shifted) indicates index=0 in old scenario)
    int solve3(int ind1 , int ind2 , int n , int m , string &text1, string &text2,vector<vector<int>>&dp){

        if(ind1==n-1 || ind2==m-1) return 0;
        if(dp[ind1+1][ind2+1]!=-1) return dp[ind1+1][ind2+1];
        //match 
        if(text1[ind1+1]==text2[ind2+1]){
            int match = 1 +  solve3(ind1+1,ind2+1,n,m,text1,text2,dp) ; 
            return dp[ind1+1][ind2+1]= match;
        }
        //not-match 
        if(text1[ind1+1]!=text2[ind2+1]){ 
            //two calls
            int pos1 =  solve3(ind1+1,ind2,n,m,text1,text2,dp) ; 
            int pos2 =  solve3(ind1,ind2+1,n,m,text1,text2,dp) ; 
            int notMatch = max(pos1,pos2); 
            return dp[ind1+1][ind2+1]=notMatch;
        } 

    return 0;
    }
       //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int solve6(int ind1 , int ind2 , int n , int m , string &text1, string &text2,vector<vector<int>>&dp){

        if(ind1==0|| ind2==0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

       //match 
        if(text1[ind1-1]==text2[ind2-1]) return dp[ind1][ind2]= 1 +  solve6(ind1-1,ind2-1,n,m,text1,text2,dp)  ;
        
        //not-match 
        return dp[ind1][ind2]=max(solve6(ind1-1,ind2,n,m,text1,text2,dp) , solve6(ind1,ind2-1,n,m,text1,text2,dp));
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (-1,-1) -> After Left shifting of index(index=-1 (left shifted) indicates index=0 in old scenario)
    int tabulation(string &text1, string &text2){
        int n = text1.size() , m = text2.size() ; 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //base case 
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
               if (i == n || j == m) {
                   dp[i][j] = 0;
               } 
            }
        }

        for(int ind1=n-2;ind1>=-1;ind1--){
            for(int ind2=m-2;ind2>=-1;ind2--){
                //match
                if(text1[ind1+1]==text2[ind2+1]){ 
                //    cout<<text1[ind1+1]<<" "<<text2[ind2+1]<<"\n";
                    dp[ind1+1][ind2+1] = 1 + dp[ind1+2][ind2+2];
                }
                else{ 
                     int pos1 =  dp[ind1+2][ind2+1]  ;
                    int pos2 =  dp[ind1+1][ind2+2] ;
                    dp[ind1+1][ind2+1] = max(pos1,pos2); 
                }
            }
        }
       /* for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
    return dp[0][0];
    }

     //Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulation2(string &text1, string &text2){
        int n = text1.size() , m = text2.size() ; 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //base case for i=0 -> j varis from 0 to m
             for (int j = 0; j < m + 1; j++) {
                    dp[0][j] = 0;
               } 
           //  for j=0 -> i varis from 0 to n
             for (int i = 0; i < n + 1; i++) {
                    dp[i][0] = 0;
               } 

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){ 
                //match
                if(text1[ind1-1]==text2[ind2-1]){ 
                     dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{ 
                     int pos1 =  dp[ind1][ind2-1]  ;
                    int pos2 =  dp[ind1-1][ind2] ;
                    dp[ind1][ind2] = max(pos1,pos2); 
                }
            }
        }
        /* for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        } */
    return dp[n][m];
    }

     //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    //Recursion call from (-1,-1) -> After Left shifting of index(index=-1 (left shifted) indicates index=0 in old scenario)
    int tabulationWithSpaceOptimization(string &text1, string &text2){
        int n = text1.size() , m = text2.size() ; 
         vector<int>prev(m+1,0),curr(m+1,0);

        //base case :- for i=n , j varies from 0 to m (prev row) 
        //no need to make curr = 0 for all i -> from 0 to n (when j=m)[as it is column part and not needed]
             for (int j = 0; j < m + 1; j++) {
                    prev[j] = 0;
                }
   
   // ind1+1,ind2+1 -> means curr row && ind1+1,ind2+1 -> means prev row
        for(int ind1=n-2;ind1>=-1;ind1--){
            for(int ind2=m-2;ind2>=-1;ind2--){
                //match
                if(text1[ind1+1]==text2[ind2+1]){ 
                //    cout<<text1[ind1+1]<<" "<<text2[ind2+1]<<"\n";
                    curr[ind2+1] = 1 + prev[ind2+2];
                }
                else{ 
                     int pos1 =  prev[ind2+1]  ;
                    int pos2 =  curr[ind2+2] ;
                    curr[ind2+1] = max(pos1,pos2); 
                }
            }
            prev=curr;
        }
    //    for(auto it : prev) cout<<it<<" ";
    return prev[0];
    }

    //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulationWithSpaceOptimization2(string &text1, string &text2){
        int n = text1.size() , m = text2.size() ; 
         vector<int>prev(m+1,0),curr(m+1,0);

        //base case :- for i=0 , j varies from 0 to m (prev row) 
        //no need to make curr = 0 for all i -> from 0 to n (when j=0)[as it is column part and not needed]
             for (int j = 0; j < m + 1; j++) {
                    prev[j] = 0;
                }
   
         for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){ 
                //match
                if(text1[ind1-1]==text2[ind2-1]){ 
                    curr[ind2] = 1 + prev[ind2-1];
                }
                else{ 
                     int pos1 =  curr[ind2-1]  ; //as dp[ind1][ind2-1] -> ind1 indicated curr row
                    int pos2 =  prev[ind2] ;//as dp[ind1-1][ind2] -> ind1-1 indicated prev row
                    curr[ind2] = max(pos1,pos2); 
                }
            }
            prev=curr;
        }
    //    for(auto it : prev) cout<<it<<" ";
    return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size() ;
          
        //  return solve(0,0,n,m,text1,text2); //Approach-1 Recursion

     //  vector<vector<int>>dp(n,vector<int>(m,-1));
     //  return solve2(0,0,n,m,text1,text2,dp);  //Approach-2 Memoization

     //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // int ans =  solve3(-1,-1,n,m,text1,text2,dp);

       /* for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        */
     //  return ans;  //Approach-2 Memoization
     // return tabulation(text1,text2) ;  //Approach-3 tabulation 
        
     //   return tabulationWithSpaceOptimization(text1,text2) ; //Approach-4 tabulationWithSpaceOptimization 

     //ALL CALLS FROM (n-1,m-1) & after right shifting from (n,m) 
      // return solve4(n-1,m-1,n,m,text1,text2); //Approach-1 Recursion
       
        //  vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve5(n-1,m-1,n,m,text1,text2,dp);  //Approach-2 Memoization
      
       //vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); // of size n+1 & m+1 as right shifted
       //return solve6(n,m,n,m,text1,text2,dp);  //Approach-2 Memoization after right shifting of index

    //  return tabulation2(text1,text2) ;  //Approach-3 tabulation 
     return tabulationWithSpaceOptimization2(text1,text2) ; //Approach-4 tabulationWithSpaceOptimization 
    }

    int longestPalindromeSubseq(string s) {
        //LCS Observation 
        //Take reverse string of s and than find LCS of it and it is the longest palindrome subsequence
        //as the original string was reversed and than we found some common subsequence between them
        //and that is bound to be LPS (longest palindrome subsequence)
        int n=s.size();
        string t = s ;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};
