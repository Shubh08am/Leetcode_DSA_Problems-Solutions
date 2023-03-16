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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //DSU 
    int n = edges.size();
    DisjointSet ds(n);
    vector<int>ans;
    for(auto& it : edges){ 
         //if,connected i.e same Ultimate Parent and candidate of answer 
       if(ds.findUltimateParent(it[0])==ds.findUltimateParent(it[1])){
           ans={it[0],it[1]};
       }
       else{//if not connected connect dynamically using dsu 
    //    ds.UnionBySize(it[0],it[1]);
        ds.UnionByRank(it[0],it[1]);
       }
    }
    return ans;
    }
};
