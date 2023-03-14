class DSU{
public:
vector<int>parent , rank , size ; 
//constructor created 
DSU(int n){
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
    private: 
    bool isValid(int newRow,int newCol , int n){
        return (newRow>=0 && newRow<n && newCol>=0 && newCol<n) ; 
    }
public: //T.C = O(N^2) , S.C = O(2*N) [for parent and size vector]
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        DSU ds(n*n) ; //total n*n nodes 
         
         //for 4 direction traversal 
         int dx[] = {-1,0,+1,0} ;
         int dy[] = {0,+1,0,-1} ;

        //STEP-1 MAKE DSU READY IF 1 EXIST MAKE CONNECTION :- T.C = O(N^2*4) 
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                  //else it is 1 traverse 4 direction and connect 
                  for(int ind=0;ind<4;ind++){
                      int newRow = row + dx[ind] ; 
                      int newCol = col + dy[ind] ; 
                
                //check valid and 1 exist than only connect 
                if(isValid(newRow,newCol,n) && grid[newRow][newCol]==1){
                    //make connection using cell no. 
                    int nodeNo = row*n+col ; //first cell to be connected 
                    int adjNodeNo = newRow*n+newCol ; //second cell to be connected 
                    ds.UnionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }

            //STEP-2 GO TO EVERY 0 AND TRY TO CONVERT IT TO 1 AND SEE SIZE :- T.C = O(N^2*4) + log(N) [logN will be very small therefore ignored]
            int maxSize=0 ; 

          for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                  //else it is 0 traverse 4 direction and see if any 1 exist if yes insert its ultimate parent in set 
                  set<int>Components; //stores unique  Ultimate Parent
                  for(int ind=0;ind<4;ind++){
                      int newRow = row + dx[ind] ; 
                      int newCol = col + dy[ind] ; 
                
                //check valid and 1 exist than only connect 
                if(isValid(newRow,newCol,n) && grid[newRow][newCol]==1){
                   //insert in set its Ultimate Parent 
                   int cellNo = newRow*n+newCol;
                   Components.insert(ds.findUltimateParent(cellNo));
                }
             }
                //see size now 
                int size=0;
                for(auto&it : Components) size+=ds.size[it];
                maxSize = max(maxSize,size+1); //size+1 as converting 0 to 1
                }
            }
        
        //EDGE CASE :- if all 1 than ds.size[0] will include max size as all will be connected to it
        // or do one more traversal to check 
      
      //Approach 1:- 
      //  maxSize = max(maxSize,ds.size[0]);
      //Approach 2 :- 
            for(int cellNo=0;cellNo<n*n;cellNo++){
                int ultimateParentOfEveryNode = ds.findUltimateParent(cellNo) ;
                maxSize = max(maxSize,ds.size[ultimateParentOfEveryNode]);
            }
    return maxSize;
    }
};
