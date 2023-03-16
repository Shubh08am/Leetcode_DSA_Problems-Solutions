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
    int minCostConnectPoints(vector<vector<int>>& points) {
        //Minimum Spanning Tree , DSU
        //Use Kruskal's Algorithm or Prism 
         //Approach-1 :-  Kruskal's Algorithm:-
         int n = points.size();  
         DisjointSet ds(n) ;    

        // first value store weight where
        // weight is actually manhattan distance
         vector<pair<int,pair<int,int>>> adj;
        
        for(int i = 0; i < n; i++){ 
            //start j from i+1 as we already calculated before part earlier
            //ex:- i=4 and j=5 will be calculated first time but j=0 to 4 is calculated earlier
            for(int j = i+1 ; j < n; j++){
                 //manhattan distance
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({weight, {i, j}});
            }
        }
        
        // sort on the basis of their edge weight
        sort(adj.begin(), adj.end());
        int mstWt = 0;
        
        for(int i = 0; i < adj.size(); i++){
            int u = adj[i].second.first ;
            int v = adj[i].second.second ;
            int wt = adj[i].first ;
            if(ds.findUltimateParent(u)!= ds.findUltimateParent(v)){ // if both parents are not same then add weight
                mstWt += wt;
                ds.UnionBySize(u,v); //connect them 
               //ds.UnionByRank(u,v);
            }
        }
        return mstWt; 
    }
};
