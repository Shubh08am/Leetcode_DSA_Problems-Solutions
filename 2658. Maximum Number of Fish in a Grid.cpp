class Solution {
public:
          
        void DFS(vector<vector<int>>& grid,vector<vector<int>>& vis, int row, int col,int&islands) {
            islands+=grid[row][col];
            vis[row][col]=1;
        int n = grid.size() , m = grid[0].size() ;
        vector<int>delrow = {-1,0,+1,0}; 
        vector<int>delcol = {0,-1,0,+1};
            
         for(int i = 0 ; i<4 ; i++){ 
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               
               //check valid or not 
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                   DFS(grid,vis,nrow,ncol,islands);
                }
         }
             
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
      
         int ans=0;
        int n = grid.size() , m = grid[0].size() , cnt=0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
         for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                 if(!vis[i][j] && grid[i][j] >0) {
                     int islands=0;
                    DFS(grid,vis, i, j,islands);
                      ans=max(ans,islands);
                } 
            }
        }
        return ans;
    }
};
