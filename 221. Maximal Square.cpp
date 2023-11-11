class Solution {
public:

    int maximalSquare2(vector<vector<char>>& matrix) {
    //dp[i][j]=min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1 
       int n=matrix.size() , m=matrix[0].size(),maxLen=0;
       vector<vector<int>>dp(n,vector<int>(m,0)) ; 
       
       //first row copied 
       for(int i=0;i<m;i++) dp[0][i]=matrix[0][i]-'0' ; 

        //first col copied 
       for(int j=0;j<n;j++) dp[j][0]=matrix[j][0]-'0' ; 

       for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
               if(matrix[i][j]=='0') dp[i][j]=0;
               
               if(matrix[i][j]=='1'){
                dp[i][j]=min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1 ; 
                }
           }
       }
      for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            maxLen=max(maxLen,dp[i][j]) ;
           }
      }
       return maxLen*maxLen;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        return maximalSquare2(matrix) ;


    }
};
