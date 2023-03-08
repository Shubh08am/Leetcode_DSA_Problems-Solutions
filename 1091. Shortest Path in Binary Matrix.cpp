class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         
        int n = grid.size() , m = grid[0].size() ; 
        pair<int, int> source={0,0};
        pair<int, int> destination={n-1,m-1};

        //edge case:- (1) if at starting only source equals destination == 1 , not possible to reach end
        // (2) if n==1 and only 0 present return 1 or if at top-left or bottom-right no 0 return -1
         if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        if(grid[0][0]==0 && n==1) return 1;
        
         vector<vector<int>>vis(n,vector<int>(m,0)) ; 
         // mark source as visited 
         vis[source.first][source.second]=1;
         queue<pair<int,pair<int,int>>> q;
         q.push({0,{source.first,source.second}});
         
         //8 direction traversal 
         int dx[]={+1,0,+1,-1,-1,-1,0,+1};
         int dy[]={0,+1,+1,0,+1,-1,-1,-1};

    
         while(!q.empty()){
             auto it = q.front();
             q.pop();
             int dis = it.first ; 
             int row = it.second.first , col = it.second.second; 
             // or return here 
           // if(row==destination.first && col==destination.second) return dis;
             //traverse all 8 direction 
             for(int i=0;i<8;i++){
                 int newRow = row + dx[i] ; 
                 int newCol = col + dy[i] ; 
      
      
                 //check valid && 0 at grid  
         if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==0 && !vis[newRow][newCol]){
                //reach destination 
      if(newRow==destination.first && newCol==destination.second) return dis + 2;
                vis[newRow][newCol] =  1 ;
                q.push({dis + 1 ,{newRow,newCol}});
            }
             }
         }

         return -1; //not able to reach destination
    }
};
