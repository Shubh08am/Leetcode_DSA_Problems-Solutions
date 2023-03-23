class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& g) {
        int n = g.size() , m = g[0].size() ; 
         int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
         int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        int a=1; int p=0;
        int x=0,y=0;
        long t = n*m , qp=0;
        //dfs
        queue<pair<int,int>>q;
        q.push({0,0}) ; 
        
        while(!q.empty()){
            bool flg=0;
              int x = q.front().first , y = q.front().second ; 
            q.pop() ; 
            
             for (int k = 0; k< 8;k++) {
                     int nx = x+ dx[k];
                    int ny = y + dy[k];
                 
                 if(nx>=0&&nx<n &&ny>=0&&ny<n&&g[nx][ny]==qp+1){
                           x=nx;
                         y=ny;
                         flg=1;
                         break;
                  }}
           //if found 
                 if(flg){
                     q.push({x,y});
                 }
                     qp+=1;
                 
        }
        
      //  if(q!=p+1){
      //          return 0;
      //      }
        return qp==t;
    }
};
