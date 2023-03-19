class Solution {
private:
    bool isValid(int nRow,int nCol,int n){
        return nRow>= 0 && nRow<n && nCol>=0 && nCol<n;
    }
    void dfs(int row,int col, vector<vector<int>>& grid,vector<pair<int,int>>& island,
            vector<int>& delRow,vector<int>& delCol,vector<vector<int>>&vis){
        int n=grid.size();
         vis[row][col]=1;
        island.push_back({row,col});
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(isValid(nRow,nCol,n) && grid[nRow][nCol]==1 && !vis[nRow][nCol]){
                dfs(nRow,nCol,grid,island,delRow,delCol,vis);
            }
        }
    }
    
    int getMinFlips(vector<pair<int,int>> &island1,vector<pair<int,int>> &island2){
        int minDist=INT_MAX;
        for(int i=0;i<island1.size();i++){
            for(int j=0;j<island2.size();j++){
                int x1=island1[i].first;
                int x2=island2[j].first;
                int y1=island1[i].second;
                int y2=island2[j].second;
                //distance between two island 
                //ex:- co-ordinates(2,3) -- (3,2) has 1 island in between them therefore abs(2-3)+abs(3-2)-1 = 1
                int dist=abs(x1-x2)+abs(y1-y2)-1;
                minDist=min(minDist,dist);
            }
        }
        return minDist;
    }
public:   
    int shortestBridge(vector<vector<int>>& grid) {
     //only 2 island given 
     //find smallest distance between two islands 
     //we can store co-ordinates of both islands and than see distance between them & minimize them 

        int n=grid.size();
        vector<pair<int,int>> island1;
        vector<pair<int,int>> island2;
        vector<int> delRow{-1,0,1,0};
        vector<int> delCol{0,1,0,-1};
        int islandCnt=0;
        vector<vector<int>>vis(n,vector<int>(n,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 &&!vis[row][col]){
                    islandCnt++;
                    if(islandCnt==1){//first island found
                        dfs(row,col,grid,island1,delRow,delCol,vis);
                    }
                    else if(islandCnt==2){//second island found
                        dfs(row,col,grid,island2,delRow,delCol,vis);
                    }
                }
            }
        }
        int minDist=getMinFlips(island1,island2);

        return minDist;
    }
};
