#define ppi pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int newRow,int newCol,int m,int n){
        return newRow>=0 && newCol>=0 && newRow<m && newCol<n ; 
    }
    pair<int,int> getCoordinate(int type,int newRow,int newCol){
        if(type==1){
            return {newRow,newCol+1} ; 
        }
        if(type==2){
            return {newRow,newCol-1} ; 
        }
        if(type==3){
            return {newRow+1,newCol} ; 
        }
        else{
            return {newRow-1,newCol} ; 
        }
    }
    int minCost(vector<vector<int>>& grid) {
        // Dijkstra Algorithm 
        //at each cell with how many minimum cost can we reach  
        //T.C -> O(ELOG(V)) -> Here , V = M*N AND E = M*N 
        //S.C -> O(M*N)
        int m = grid.size() , n = grid[0].size() ; 
        vector<vector<bool>>vis(m,vector<bool>(n,0)) ;  
        vector<vector<int>>CellCost(m,vector<int>(n,1e7)) ;  
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq; 
        pq.push({0,{0,0}}) ; 
        vis[0][0]=1;
        CellCost[0][0]=0;

        vector<pair<int,int>>dir = {{0,-1},{0,+1},{-1,0},{+1,0}} ; 

        while(!pq.empty()){
            auto node = pq.top() ; 
            pq.pop() ; 
            int cost = node.first ; 
            int row = node.second.first , col = node.second.second ; 
        //    cout << row << " " << col << " " << cost << "\n" ;
            vis[row][col]=1;
            
            if(row == m-1 && col == n-1){
                return cost;
            }

            pair<int,int> pos = getCoordinate(grid[row][col],row,col) ; 

            for(int i=0;i<4;i++){
                int newRow  = row + dir[i].first ; 
                int newCol = col + dir[i].second ; 

                if(isValid(newRow,newCol,m,n) && !vis[newRow][newCol]){
                    //move without cost 
                    if(pos.first == newRow && pos.second == newCol){
                        pq.push({cost,{newRow,newCol}});
                        CellCost[newRow][newCol] = cost ; 
                    }
                    //move with cost 
                    else{
                        if(cost+1 < CellCost[newRow][newCol]){
                        pq.push({cost+1,{newRow,newCol}});
                        CellCost[newRow][newCol] = cost + 1; 
                        }
                    }
                }
            }
        }
    return CellCost[m-1][n-1] ;
    }
};
