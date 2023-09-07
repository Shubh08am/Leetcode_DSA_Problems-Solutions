class Solution {
public:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m ;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        // at each cell by removing how much minimum obstacle can we reach 
        // think dijkstra's Algorithm 

        // dp won't work 
        // time complexity is (O(V+E)logV)
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e5)) ; 
        dist[0][0]=0; 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}}) ; 
        int dx[]={0,0,-1,+1} , dy[]={-1,+1,0,0}; 

        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop() ; 
            int row = it.second.first , col = it.second.second;
            int obstacles = it.first ; 
            //every time reaching the cell with least obstacles 
            if(row == n-1 && col == m-1) return obstacles;
            for(int i=0;i<4;i++){
                int nr = row + dx[i] ; 
                int nc = col + dy[i] ; 
            // [x,y] pe with a obstacle pahuch gye 
            // ab [l,m] pe kaise pahuchenge from [x,y] using adjacent [row,col] only 
            // so agar [l,m] bhi obstacle hain tho cnt = 1 [for [l,m]] + a [for [x,y]] 
            //now if  1 [for [l,m]] + a [for [x,y]]  is less than obstacle to reach till [l,m] update it 
            
                if(isValid(nr,nc,n,m) && dist[nr][nc] > obstacles + grid[nr][nc]){
                    dist[nr][nc]  = obstacles + grid[nr][nc] ;
                    pq.push({dist[nr][nc] ,{nr,nc}}) ;
                }
            }
        }
    return dist[n-1][m-1] ; 
    }
};
