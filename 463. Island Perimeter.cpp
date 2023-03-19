class Solution {
public:
    int bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &visited){
        visited[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q; 
        q.push({row,col});
        int perimeter=0;
        while(!q.empty()){
            perimeter+=4; 
            int row=q.front().first,col=q.front().second; q.pop();
            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+dx[i],ncol=col+dy[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]){
                    perimeter--;//as counted 4 times earler common boundary exist 

                    if(!visited[nrow][ncol]){
                        visited[nrow][ncol]=1; 
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                     return bfs(i,j,grid,visited);
                }
            }
        }
        return 0;
    }
};
