class Solution {
public:
bool isValid(int nrow , int ncol , int n ,int m){
    return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
}
    void dfs(int row , int col , vector<vector<int>> &vis , vector<vector<int>> &grid){
        
    int dx[]={-1,0,+1,0};
    int dy[]={0,-1,0,+1};
    int n = grid.size(),m = grid[0].size();

    vis[row][col] = 1;  //mark visited  
    
    for(int i=0;i<4;i++){
        int nrow = row+dx[i] ;
        int ncol = col+dy[i];
        //check valid 
        if(isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && !grid[nrow][ncol]){
            dfs(nrow,ncol,vis,grid);
        }
    }
}
    int closedIsland(vector<vector<int>>& grid) {
        //count total 0's component - component of 0's at corners 
        //make dfs call two times separately 
        //first for boundary condition 
        //second for non-boundary condition and keep count of total dfs call made this is the ans

    int n = grid.size(),m = grid[0].size();
    vector<vector<int>>vis(n,vector<int> (m , 0));
    int Boundary=0 ;
    for(int i=0 ; i<n ;i++){
        //first row check
        if(!vis[i][0] && grid[i][0]==0){
            dfs(i , 0 , vis , grid);
            Boundary++;
        }
        //last row check
        if(!vis[i][m-1] && grid[i][m-1]==0){
            dfs(i , m-1 , vis , grid);
            Boundary++;
        }
    }

    for(int i=0 ; i<m ;i++){
        //first column check
        if(!vis[0][i] && grid[0][i]==0){
            dfs(0 , i , vis , grid);
            Boundary++;
        }
        //last column check
        if(!vis[n-1][i] && grid[n-1][i]==0){
            dfs(n-1 , i , vis , grid);
            Boundary++;
        }
    }
    
    int nonBoundary=0 ;
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<m ;j++){
            if(!vis[i][j] && grid[i][j]==0){
                nonBoundary++;
                dfs(i , j , vis , grid);
            }
        }
    }
    // cout<<nonBoundary<<" "<<Boundary;
    return nonBoundary;
    }
};
