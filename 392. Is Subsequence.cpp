class Solution {
public:
    bool isSubsequence(string s, string t) {
    int n = s.size() , m = t.size() ; 
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
                if(s[ind1+1]==t[ind2+1]){ 
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
    return dp[0][0]==n;
    }
};
   
