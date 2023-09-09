#define ppi pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int nr,int nc,int m,int n){
        return nr>=0 && nc>=0 && nr<m && nc<n ;
    }
    int minimumTime(vector<vector<int>>& grid) {
        // dijkstra 
        int m = grid.size() , n = grid[0].size() ; 
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        //not able to make even first move 
        if(grid[0][1]>grid[0][0]+1 && grid[1][0]>grid[0][0]+1) return -1;

        pq.push({grid[0][0],{0,0}}) ; 
        vis[0][0]=1;

        vector<pair<int,int>>dir = {{0,-1} , {0,+1} , {1,0} , {-1,0}} ; 

        while(!pq.empty()){ 
            auto it = pq.top() ;
            pq.pop(); 
            int r = it.second.first , c = it.second.second ; 
            int currTime = it.first ; 
         //   cout << currTime << "\n";

            if(r==m-1 && c==n-1) return currTime;

            for(int i=0;i<4;i++){
                int nr = r + dir[i].first ; 
                int nc = c + dir[i].second ; 

                if(isValid(nr,nc,m,n) && !vis[nr][nc]){
                    int requiredTime = grid[nr][nc] - currTime ;

                    //reaching a node with excess of time than only 1 unit time required to go further
                    if(requiredTime <= 1) requiredTime=1;

                    //if time is even we need one extra time  
                    if(requiredTime%2==0) requiredTime++;

                  if(currTime+requiredTime >= grid[nr][nc] && !vis[nr][nc]){
                    pq.push({currTime+requiredTime,{nr,nc}}) ;
                    vis[nr][nc]=1;
                    }
                }
            }
        }
    return -1;
    }
};
