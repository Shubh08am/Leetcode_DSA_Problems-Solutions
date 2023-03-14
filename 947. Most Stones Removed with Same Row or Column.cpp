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
    int removeStones(vector<vector<int>>& stones) { 
        int maxRow=0 , maxCol=0 ;
        //finding dimension of grid & row & col required 
        for(auto&it : stones){
            maxRow=max(maxRow,it[0]) ; 
            maxCol=max(maxCol,it[1]) ; 
        }

        DisjointSet ds(maxRow+maxCol+1); //ds created with Total node as maxRow+maxCol+1 
        
        //Approach-1  USING PARENT AND SIZE (WITHOUT HASHING)
        /*
        //assign,both row & column as a node 
          for(auto&it : stones){
             int nodeOfRow = it[0] ; //row assigned as node
             int nodeOfCol = it[1] + maxRow + 1 ;   //column assigned as node by mapping it to start just after maxRow 
             //connect them dynamically, using DSU 
             ds.UnionBySize(nodeOfRow,nodeOfCol);
          }

        int components=0;//total components present in stones 
        //iterate till maxRow+maxCol+2 as if - 
        
         //     maxRow = 4 && maxCol=3 
        //      than nodeOfRow=0,1,2,3,4 && nodeOfCol=5,6,7,8 
        //      I.e total (4+1)+(3+1) = 9 nodes and iterate till 8 as nodeNo till 8 
        

        for(int i=0;i<maxRow+maxCol+2;i++){
    //if boss i.e topmost guy and valid component(same Ultimate Parent) i.e it has some stone attached to it than its size should be > 1
            if(ds.parent[i]==i && ds.size[i]>1){
                components++;//valid components
            }
        }
        //If in a components we have x stone , we can remove (x-1) stones from it.
        //In, total total size(of stones) - all valid components gives us result --> see derivation from striver op video
        return stones.size()-components;
     */
       
        //Approach-2 :- USING HASHING 
        unordered_map<int,int>stonesNodes ; 
        for(auto&it : stones){
             int nodeOfRow = it[0] ; //row assigned as node
             int nodeOfCol = it[1] + maxRow + 1 ;   //column assigned as node by mapping it to start just after maxRow 
             //connect them dynamically, using DSU 
             ds.UnionBySize(nodeOfRow,nodeOfCol);
             //assign in stonesNodes that stones find for row & col at nodeOfRow & nodeOfCol 
             stonesNodes[nodeOfRow]=1;
             stonesNodes[nodeOfCol]=1;
          }
        
        int components=0;//total components present in stones
        //Now,see in map for valid Components(same Ultimate Parent) 
        for(auto&it: stonesNodes){ 
            //topmost guy
            if(ds.findUltimateParent(it.first)==it.first){
                 components++;
            }
        }
        return stones.size()-components;
    }
};
