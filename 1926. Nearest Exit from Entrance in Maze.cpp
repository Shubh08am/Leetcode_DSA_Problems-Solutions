class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //dfs or bfs works 
        int n = maze.size() , m = maze[0].size();
      //  {{row,col},step}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int atR = entrance[0] , atC = entrance[1] ;
        q.push({{atR,atC},0});
        vis[atR][atC]=1;
          //4 direction traversal 
           int dx[]={-1,0,+1,0} ; 
           int dy[]={0,-1,0,+1} ;
    
        while(!q.empty()){ 
            int row = q.front().first.first , col = q.front().first.second;
            int step = q.front().second;

           q.pop();
           //not at entrance
           if((row==0 || row==n-1 || col==0 || col==m-1) && (row!=atR || col!=atC)){
               return step;
           }
           for(int i=0;i<4;i++){
              int nrow = row+dx[i] ; 
              int ncol = col+dy[i];
               //check valid and condition 
              if(isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && maze[nrow][ncol]=='.'){
                  vis[nrow][ncol]=1;
                  q.push({{nrow,ncol},step+1});
              }
        }
     }
        return -1;//not possible to exist -1
    }
};
