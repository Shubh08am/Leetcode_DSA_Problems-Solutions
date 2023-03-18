class Solution {
public:
     void bfs(int row, int col , vector<vector<char>>& grid,vector<vector<int>>& vis, int n , int m , vector<int>delrow , vector<int>delcol ){
      vis[row][col]=1;
      queue<pair<int,int>>q;
      q.push({row,col});
      
      while(!q.empty()){
          int row = q.front().first ; 
          int col = q.front().second ; 
          q.pop();
          //all neighbours i.e 4 
          for(int i = 0 ; i<4 ; i++){ 
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               
               //check valid or not 
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
               }
          }
      }
  }
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size() , m = grid[0].size() , cnt=0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>delrow = {-1,0,+1,0}; 
        vector<int>delcol = {0,-1,0,+1};
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                //if not vis and 1 
                if(!vis[row][col] and grid[row][col]=='1'){
                    //do bfs or dfs 
                    cnt++;
                    bfs(row,col,grid,vis,n,m,delrow,delcol);
                }
            }
        }
        return cnt;
    }
};
