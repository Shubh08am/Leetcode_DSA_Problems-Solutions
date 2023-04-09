class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(2^max(N,M)) Space Complexity: O(N+M) [max depth of recursive stack.]
    //Recursion call from (n,m)
    int solve(vector<int>& s1, vector<int>& s2, int i , int j , int cnt){
        if(i==0 || j==0) return cnt;
        
        //match case
        if(s1[i-1]==s2[j-1]){
            cnt=solve(s1,s2,i-1,j-1,cnt+1);
        }
        
        //for not match case 
        cnt=max(cnt, max(solve(s1,s2,i-1,j,0), solve(s1,s2,i,j-1,0))) ;
        return cnt;
    } 
    
     //Approach-2 Memoization :- Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
    //Recursion call from (n,m) -> After right shifting of index(index=n (right shifted)
    //indicates index=n-1 in old scenario)  
    int maxi=0; //for LCSS [Using global variable] else we need to use 3d dp than 1 state for maxi as well
       int solve2(vector<int> &s1, vector<int>&s2, int i , int j , vector<vector<int>>&dp){
         int n = s1.size() , m = s2.size();
         
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //match case
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+ solve2(s1,s2,i-1,j-1,dp);
            maxi=max(maxi,dp[i][j]);
        }
        //for not match case 
        else{
             dp[i][j]=0;
        }
        
        //traverse furhter string
         solve2(s1,s2,i-1,j,dp);
         solve2(s1,s2,i,j-1,dp) ;
         
        return dp[i][j];
    } 
  
    
//Approach-3 Tabulation :- Time Complexity: O(N*M) Space Complexity: O(N*M)
    //Recursion call from (n,m) -> After right shifting of
    //index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulation(vector<int>& S1, vector<int>& S2, int n, int m){
        int  maxi=0;
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ; 
	     
	     for(int i=1;i<=n;i++){
	         for(int j=1;j<=m;j++){
	             if(S1[i-1]==S2[j-1]){
	                 dp[i][j] = 1 + dp[i-1][j-1];
					 maxi=max(maxi,dp[i][j]);
	             }
	             else{
	                 dp[i][j] = 0;
	             }
	         }
	     }
	     return maxi;
    }
//Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
//Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulationWithSpaceOptimization(vector<int> &s1, vector<int>&s2){
        int n = s1.size() , m = s2.size() , maxi=0; 
         vector<int>prev(m+1,0),curr(m+1,0);

        //base case :- for i=0 , j varies from 0 to m (prev row) 
        //no need to make curr = 0 for all i -> from 0 to n (when j=0)[as it is column part and not needed]
             for (int j = 0; j < m + 1; j++) {
                    prev[j] = 0;
                }
   
         for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){ 
                //match
                if(s1[ind1-1]==s2[ind2-1]){ 
                    curr[ind2] = 1 + prev[ind2-1];
                    maxi=max(maxi,curr[ind2]);
                }
                else{ 

                    curr[ind2] = 0; 
                }
            }
            prev=curr;
        }
     return maxi;
    }
    
    //Approach-5 tabulation With Space Optimization :- Time Complexity: O(N*M) Space Complexity: O(M)
    // USING ONE ROW ONLY
//Recursion call from (n,m) -> After right shifting of index(index=n (right shifted) indicates index=n-1 in old scenario)
    int tabulationWithSpaceOptimization2(vector<int>&s1, vector<int>&s2){
        int n = s1.size() , m = s2.size() , maxi=0; 
         vector<int>prev(m+1,0);

        //base case :- for i=0 , j varies from 0 to m (prev row) 
        //no need to make curr = 0 for all i -> from 0 to n (when j=0)[as it is column part and not needed]
             for (int j = 0; j < m + 1; j++) {
                    prev[j] = 0;
                }
          for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=m;ind2>0;ind2--){ 
                //match
                if(s1[ind1-1]==s2[ind2-1]){ 
                    //Update in prev only i.e overwrite curr[ind2] value in prev[ind2]
                    //as we only need left part of prev as ind2-1 and we are traversing from m --> 0 now 
                    prev[ind2] = 1 + prev[ind2-1];
                    maxi=max(maxi,prev[ind2]);
                }
                else{ 
                  prev[ind2] = 0; 
                }
            }
        }
    //    for(auto it : prev) cout<<it<<" ";
     return maxi;
    }

    int findLength(vector<int>& s1, vector<int>& s2) {
      //longest common sub-string 

        int n=s1.size(),m=s2.size();
	    
      //   return solve(s1,s2,n,m,0);  //Approach-1 Recursion
        
      //  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     //     solve2(s1,s2,n,m,dp);  //Approach-2 Memoization 
      //  return maxi; // stores longest common subarray in maxi length
          
    
      //  return tabulation(s1,s2,n,m); //Approach-3 tabulation 
        
     //    return tabulationWithSpaceOptimization(s1,s2);  //Approach-4 tabulationWithSpaceOptimization
       
       return tabulationWithSpaceOptimization2(s1,s2);  //Approach-5 tabulationWithSpaceOptimization2
    }
};
