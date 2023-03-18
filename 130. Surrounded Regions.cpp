class Solution {
public: 
// T.C -> O(n*m*4) + O(n)
// S.C -> O(n*m) +  O(n*m) -> O(n*m)
 // dfs for n*m*4 
   void dfs(int row , int col ,vector<vector<char>>&board,vector<vector<int>>&vis , vector<int>delRow, vector<int>delCol){
       vis[row][col]=1;
       int n = board.size() , m = board[0].size();
       //check all 4 direction
       for(int i=0;i<4;i++){
           int nrow = row+delRow[i];
           int ncol  = col+delCol[i];

           //if valid 
           if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and board[nrow][ncol]=='O'){
               //mark visited 
               vis[nrow][ncol]=1;
               //dfs call 
               dfs(nrow,ncol,board,vis,delRow,delCol);
           }
       }
   }
   //using bfs
    void  bfs(vector<vector<char>>& board) {
        int n=board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        // first and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                vis[0][j] = 1;
                q.push({0,j});
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                vis[n-1][j] = 1;
                q.push({n-1,j});
            }
        }
        // first and last coloum
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        vector<int>delRow={-1,0,+1,0} ; 
        vector<int>delCol={0,+1,0,-1} ; 
        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        //dfs or bfs both work 
        //if at boundary O it doesn't changes 
        //boundary -> first row,col && last row,col 
        int n = board.size() , m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //mark vis as 1 if found O 
        vector<int>delRow={-1,0,+1,0} ; 
        vector<int>delCol={0,+1,0,-1} ; 
        // O(n) 
        //check row 
        for(int j=0;j<m;j++){
              //first row 
              if(board[0][j]=='O' and !vis[0][j]){
                  //mark as visited and do a dfs call 
                   vis[0][j]=1;
                   dfs(0,j,board,vis,delRow,delCol);
              }
              //last row 
              if(board[n-1][j]=='O' and !vis[n-1][j]){
                  //mark as visited and do a dfs call 
                   vis[n-1][j]=1;
                   dfs(n-1,j,board,vis,delRow,delCol);
              }
        }
        //check col 
        for(int i=0;i<n;i++){
              //first col 
              if(board[i][0]=='O' and !vis[i][0]){
                  //mark as visited and do a dfs call 
                   vis[i][0]=1;
                   dfs(i,0,board,vis,delRow,delCol);
              }
              //last col 
              if(board[i][m-1]=='O' and !vis[i][m-1]){
                  //mark as visited and do a dfs call 
                   vis[i][m-1]=1;
                   dfs(i,m-1,board,vis,delRow,delCol);
              }
        }
      //at,last replace O which are not visited i.e which are not on boundary and in touch with them 
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(board[i][j]=='O' && !vis[i][j]) {
                  board[i][j]='X';
              }
          }
      }
    }
};
