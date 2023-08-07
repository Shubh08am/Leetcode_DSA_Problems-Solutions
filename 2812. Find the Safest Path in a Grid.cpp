class Solution {
public:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nc>=0 && nr<n && nc<m ;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // NEAREST DISTANCE OF 1 FROM EACH CELL + TAKE MAX PATH + TAKE MIN FROM MAX PATH 
        
        // NEAREST DISTANCE OF 1 FROM EACH CELL
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>>vis(n,vector<int>(m,0)) ; 
        vector<vector<int>>vis2(n,vector<int>(m,0)) ; 
        //Nearest one 
        queue<pair<int,pair<int,int>>>q; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}}) ; 
                    grid[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        
        int dx[]={0,0,-1,+1} , dy[]={-1,+1,0,0};
        
        while(!q.empty()){
            int row = q.front().second.first , col =  q.front().second.second , dist = q.front().first  ;
             grid[row][col] = dist ;
            q.pop() ; 
            
            for(int i=0;i<4;i++){
                int nr = row + dx[i] ; 
                int nc = col + dy[i] ; 
                
                if(isValid(nr,nc,n,m) && !vis[nr][nc] && !grid[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({dist+1,{nr,nc}});
                }
            }
        }
        /*
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
             cout<<"\n";
         }
        cout<<"\n";
        */
        
       // TAKE MAX PATH + TAKE MIN FROM MAX PATH  -> use max heap
        priority_queue<pair<int,pair<int,int>>>pq; 
        pq.push({grid[0][0],{0,0}}) ; 
        vis2[0][0]=1;
        while(!pq.empty()){
            int row = pq.top().second.first , col =  pq.top().second.second , dist = pq.top().first  ;
            //when reached first time return dist
            if(row==n-1 && col==m-1) return dist;
            pq.pop() ; 
            for(int i=0;i<4;i++){
                int nr = row + dx[i] ; 
                int nc = col + dy[i] ; 
                if(isValid(nr,nc,n,m) && !vis2[nr][nc]){
                    vis2[nr][nc]=1;
                    pq.push({min(dist,grid[nr][nc]),{nr,nc}});
                }
            }
        }
        return 0 ;
    }
};
