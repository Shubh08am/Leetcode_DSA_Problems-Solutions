class Solution {
public:
    int LCS(string &s,string&p){
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(s[i-1]==p[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    return dp[n][m];
    }
    //T.C -> O(LENGTH OF LARGER STRING) , HERE S IS LARGER STRING AS S = WORDS[IND] & P = WORDS[PREV_IND]
    //USING TWO POINTER
    bool compare(string&s,string&p){
        int n=s.size(),m=p.size();
        if(n-m!=1) return 0; //LENGTH OF STRING DIFFER BY 1 ONLY , HERE N>M
        int i=0,j=0;

        while(i<n){
            if(j<m && s[i]==p[j]) {
                i++;j++;
            }
            else i++;
        }
        return i==n&&j==m;//Reach end simultaneously
    }
    static bool comp(string&s,string&p){
        return s.size()<p.size();//on basis of size sorted in ascending order
    }

//USING TWO POINTER :- Time Complexity: O(N*N*LENGTH OF LARGER STRING)+O(NLOGN) Space Complexity: O(N)
 //USING LCS :- Time Complexity: O(N*N*16*16)[16*16 FOR LCS AS GIVEN CONSTRAINTS WORDS[i].length<=16]+O(NLOGN) Space Complexity: O(N)
    int longestStrChain(vector<string>& words) {
      //  sort(words.begin(),words.end(),comp); 
      // sort(words.begin(),words.end(),[&](auto &s,auto &p){return s.size()<p.size();}); //or use this 
          sort(words.begin(),words.end(),[&](const string &s,const string &p){return s.size()<p.size();}); //or use this 
           int x=words.size(),chain=1; 
           vector<int>dp(x+1,1);
        
        for(int ind=0;ind<x;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                string s=words[ind] , p=words[prev_ind];
               //  int common = LCS(s,p);
              //   if(common==min(n,m) && 1+dp[prev_ind] > dp[ind]) {
                    if(compare(s,p) && 1+dp[prev_ind] > dp[ind]){ 
                         dp[ind]=1+dp[prev_ind];
                    }
                }
             chain=max(chain,dp[ind]);
        }
         return chain;
    }
};
