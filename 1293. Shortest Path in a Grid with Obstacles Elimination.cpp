class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return (nrow>=0 && ncol>=0 && nrow<n && ncol<m);
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        vis[0][0][k]=1;
        int step=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front(); q.pop();
                int row=node.first.first,col=node.first.second,obstacle=node.second;
              
                if(row==n-1 && col==m-1) return step;

                for(auto &it : dir){
                    int nrow=row+it.first;
                    int ncol=col+it.second;
                    
                if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==0 && !vis[nrow][ncol][obstacle]){
                        vis[nrow][ncol][obstacle]=1;
                        q.push({{nrow,ncol},obstacle});
                    }
                else if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1 && obstacle>0 && !vis[nrow][ncol][obstacle-1]){
                        vis[nrow][ncol][obstacle-1]=1;
                        q.push({{nrow,ncol},obstacle-1});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
