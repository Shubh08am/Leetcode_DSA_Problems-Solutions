class DisjointSet{
public:
vector<int>parent , rank , size ; 
//constructor created 
DisjointSet(int n){
    //declare size for vector 
    parent.resize(n+1) ;  //n+1 as it covers both 0 & 1 based indexing
    rank.resize(n+1,0) ;  //initially, every node rank is marked as 0
    size.resize(n+1,1) ;  //initially, every node size is marked as 1

    //initially,every node is a parent of itself 
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

//find Ultimate Parent  
int findUltimateParent(int node){
       if(node==parent[node]) return node ; 
       //doing,path compression by assigning value to parent[node] and making T.C  as O(4*alpha) --> O(1)
       return parent[node] = findUltimateParent(parent[node]) ;
}

//Disjoint Set -> [1] finding Union By Rank 
void UnionByRank(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(rank[ulp_u]<rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        //smaller guy gets connected to larger guy and no change in rank of ulp_u or ulp_v 
        //update parent of smaller guy
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]==rank[ulp_v]){
        //Anyone can get connected to other node and change in rank of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        rank[ulp_u]++;
    }
}

//Disjoint Set -> [2] finding Union By Size 
void UnionBySize(int u , int v){
    int ulp_u = findUltimateParent(u) ; //UltimateParent of u 
    int ulp_v = findUltimateParent(v) ; //UltimateParent of v

    //if belonging to same components 
    if(ulp_u == ulp_v) return;

    //if not belonging to same components 
    if(size[ulp_u]<size[ulp_v]){
        //smaller guy gets connected to larger guy and change in size to which connected
        //update parent of smaller guy
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_u]>size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    else if(size[ulp_u]==size[ulp_v]){
        //Anyone can get connected to other node and change in size of node to which connected
        //update parent of node which gets connected
        parent[ulp_v]=ulp_u; //connecting ulp_v to ulp_u 
        size[ulp_u]+=size[ulp_v];
    }
}
};
class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DisjointSet ds(n*m);
        
        int dx[] ={-1,0,+1,0} ; 
        int dy[]={0,-1,0,+1} ; 

        vector<vector<int>>vis(n,vector<int>(m,0));
        //storing all 1 position
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                     q.push({i,j});
                }
            }
        }
        //no island present 
        if(q.size()==0) return 0;

        while(!q.empty()){
            int row = q.front().first , col =q.front().second;
            if(vis[row][col]) continue;
            else vis[row][col]=1;
            int nodeNo = row*m+col; //convert row,col to a node
            q.pop() ; 
          
           //traverse all 4 direction
            for(int ind=0;ind<4;ind++){
                int nrow = row+dx[ind] ; 
                int ncol = col+dy[ind] ; 
                int adjNodeNo = nrow*m+ncol;//convert nrow,ncol to a node

                //check valid & not visited and 1 present at grid
            if(isValid(nrow,ncol,n,m)&&!vis[nrow][ncol]&&grid[nrow][ncol]){
                //if not connected make dynamic connection using dsu
                if(ds.findUltimateParent(nodeNo)!=ds.findUltimateParent(adjNodeNo)){
                ds.UnionBySize(nodeNo,adjNodeNo) ;
                }
            }
            }
        }
        int ans=0;
        for(int i=0;i<n*m;i++){
            ans=max(ans,ds.size[i]);
        }
        return ans;
    }
};
