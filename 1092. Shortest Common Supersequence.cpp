class Solution {
public:
    //Using Memoization(for LCS) :- // Time Complexity: O(N*M) , Space Complexity: O(N*M)+O(N+M)
    int memo(string&str1,string&str2,int i,int j,vector<vector<int>>&dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j] ; 
        
        //match
        if(str1[i-1]==str2[j-1]){
            return dp[i][j] = 1 + memo(str1,str2,i-1,j-1,dp);
        }
        
        //not-match 
        return dp[i][j] = max(memo(str1,str2,i-1,j,dp),memo(str1,str2,i,j-1,dp));
    }
    // Using Tabulation :- Time Complexity: O(N*M) , Space Complexity: O(N*M)
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        
        //Tabulation :- Recursion Call from (n,m) -> i varies from n to 0 and j varies from m to 0
        //Therefore,Tabulation from i=0 to n & from j=0 to m 

          //  Finding the length of the shortest Common Supersequence

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        //BASE CASE:- when i=0 -> j varies from 0 to m  &&  when j=0 -> i varies from 0 to n

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }

        //for i=1 and j=1 onwards 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //MATCH - CASE 
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //NOT-MATCH CASE 
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }


        int lenOfSuperSequence = n+m-dp[n][m] ; //legth of shortestCommonSupersequence :- n+m-Length of LCS(str1,str2)

      //   cout<<lenOfSuperSequence<<" ";

        //  printing the shortest Common Supersequence
          int i=n,j=m;
          string ans="";
        // Till str1 or str2 is not exhausted i.e either i=0 or j=0 keep continuing 
        //i=0 & j!=0 --> indicates str1 exhausted and 1 character left from str2 
         //i!=0 & j==0 --> indicates str2 exhausted and 1 character left from str1

        while(i>0 && j>0){
                //MATCH - CASE 
            if(str1[i-1]==str2[j-1]){
               // ans+=str1[i-1]; //Both str1 & str2 reduced take char from any 
                ans+=str2[j-1]; //or use this 
                i--;j--;
            }
            // NOT-MATCH CASE 
            //Decide where to go 
            else if(dp[i-1][j] > dp[i][j-1]){
                // Go to   (i-1,j)
                //           |
                //     from (i,j)  
                ans+=str1[i-1];       //str1 reduced take char from it 
                i--;
            }
            //When equal we can go to anywhere here going to (i,j-1) from (i,j)
             else if(dp[i-1][j] <= dp[i][j-1]){
              //  (i,j-1) <-- (i,j)

                ans+=str2[j-1];       //str2 reduced take char from it 
                j--;
            }
            
        }
       // cout<<ans<<"\n";

        //Now, check for exhausted case 
        //[1] i=0 & j!=0 --> indicates str1 exhausted and 1 character left from str2 
        //[2] i!=0 & j==0 --> indicates str2 exhausted and 1 character left from str1 

      //  cout<<i<<" "<<j<<"\n";

        while(j>0){  //till str2 not exhausted
            ans+=str2[j-1]; j--;
        }

        while(i>0) { //till str1 not exhausted
            ans+=str1[i-1] ; i--;
        }
        
        //reverse ans as we moved from back(n,m) till string(either str1 or str2) got exhausted 
        reverse(ans.begin(),ans.end()); //from start ans looks like this 
        return ans;
    }
};
