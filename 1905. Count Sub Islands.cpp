class Solution {
public:  
    bool isValid(int nrow , int ncol , int n , int m){
     return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
    }
    void dfs(int row,int col ,vector<vector<int>>& grid1, vector<vector<int>>& grid2 ,vector<vector<int>>&vis,bool &check){
         int n = grid1.size() , m = grid1[0].size(); 
        vis[row][col]=1; 
        if(grid1[row][col]==0) check=0;

        int dx[] ={-1,0,+1,0} ;
        int dy[] ={0,-1,0,+1} ;

        for(int i=0;i<4;i++){
            int nrow = row + dx[i] ;
            int ncol = col + dy[i] ; 
            //check valid and also not visited earler and also grid1 also has 1 at that position 
            if(isValid(nrow,ncol,n,m) && grid2[nrow][ncol]==1 && vis[nrow][ncol]==0){
             //   cout<<grid1[nrow][ncol]<<" "<<nrow<<" "<<ncol<<"\n";
                dfs(nrow,ncol,grid1,grid2,vis,check);
             }
          }
     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //Apply dfs or union-find 
        int n = grid1.size() , m = grid1[0].size() , island=0; 
        vector<vector<int>>vis(n,vector<int>(m,0)) ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                        //make dfs call 
                         bool check=1;
                         dfs(i,j,grid1,grid2,vis,check);
                        if(check) island++;
                }
            }
        }
         return island;
    }
};
