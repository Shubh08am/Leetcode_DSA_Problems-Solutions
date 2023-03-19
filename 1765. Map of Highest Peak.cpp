class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() , m = isWater[0].size();
      //  {{row,col},step}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]) {
                    q.push({{i,j},1});
                     vis[i][j]=1;
                    }
            }
        }
           //4 direction traversal 
           int dx[]={-1,0,+1,0} ; 
           int dy[]={0,-1,0,+1} ;
    
        while(!q.empty()){ 
            int row = q.front().first.first , col = q.front().first.second;
             int height = q.front().second;
            q.pop();
           
           for(int i=0;i<4;i++){
              int nrow = row+dx[i] ; 
              int ncol = col+dy[i];
               //check valid and condition 
              if(isValid(nrow,ncol,n,m) && !vis[nrow][ncol]){
                  vis[nrow][ncol]=1;
                  ans[nrow][ncol]=height;
                  q.push({{nrow,ncol},height+1});
              }
        }
     }
        return ans;
    }
};
