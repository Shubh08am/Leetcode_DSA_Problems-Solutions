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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Approach-1 Use Simple DFS and find components and answer is components -1 if total edges >=n-1 else -1 
        // Approach-2 Use Disjoint Set to find Connected Components 
    
    DisjointSet ds(n) ; 
    
    //finding, connected components -> if same Ultimate Parent after all edges have been connected 
/* Method-1 
    for(auto it : connections){
        int u = it[0] , v = it[1] ; 
        ds.UnionBySize(u,v);
    }
    int components = 0 , edges = connections.size();
    for(int i=0;i<n;i++){ 
        //parent of itself
        if(ds.parent[i]==i) components++;
    }
    if(edges<n-1) return -1; //as n-1 edges are required to connect n nodes
    return components-1;
*/    
    //Method-2 
    int components = 0 , extraEdges = 0;
    for(auto it : connections){
        int u = it[0] , v = it[1] ; 
        //if same Ultimate Parent than already belongs to same components and extraEdge exist 
        if(ds.findUltimateParent(u)==ds.findUltimateParent(v)){
            extraEdges++;
        }
        else ds.UnionBySize(u,v);
    }
    for(int i=0;i<n;i++){ 
        //parent of itself
        if(ds.parent[i]==i) components++;
    } 
    int operation = components-1 ; 
    if(extraEdges>=operation) return operation;  
    return -1;
    }
};
