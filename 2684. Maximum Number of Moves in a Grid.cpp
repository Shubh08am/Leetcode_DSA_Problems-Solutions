class Solution {
public:
    bool isValid(int ni,int n,int nj,int m){
        return ni>=0 && ni<n && nj>=0 && nj<m ; 
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0; 
        vector<vector<int>>dp(n,vector<int>(m,0)); 
        
         
        //fill column by column 
          for(int j=m-2;j>=0;j--){ 
              for(int i=0;i<n;i++){
   
            int dx[]={-1,0,+1} ; 
            int maxMove=0 ;
            for(int k=0;k<3;k++){
                int ni = i+dx[k]; 
                int nj = j+1; 
                
                if(isValid(ni,n,nj,m) && grid[ni][nj]>grid[i][j]){
                     maxMove = max(maxMove,dp[ni][nj]+1);
                }
               }
            dp[i][j]=maxMove;
            }
        }
         for(int i=0;i<n;i++) ans=max(ans,dp[i][0]) ; 
        return ans; 
    }
};
