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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        vector<int> indegree(n,0);

    //CASE 1:- SEE FOR NO. OF PARENTS ONLY 1 PARENT SHOULD EXIST

    // indegree of a child node defines the number of directed edges 
    // coming into a child or simply its the number of parents of a child
        for(int i=0; i < n; ++i) {                                  
       // if at any moment a child has more than one parents, you simply return false
            if(leftChild[i] != -1 && ++indegree[leftChild[i]] > 1)
                return false; 
            if(rightChild[i] != -1 && ++indegree[rightChild[i]] > 1)
                return false;
        }
        
        //CASE 2:- ONLY 1 ROOT EXIST NO MULTI-COMPONENT TREE EXIST

        int root = -1;
        for(int i = 0 ; i < n; ++i){
    /*if the indegree of a child is zero its means that it is the Root node. 
    Check if there exists more than one node with indegree[0], 
    it implies than more than one root exists. 
    if root == -1 then it means that no one root exists. Therefore in both the cases return false.*/
            if(indegree[i]==0)
            root++;
        }
        if(root == -1 || root > 0) return false;

      //CASE 3:-  MAKE DYNAMIC CONNECTION VIA RANK OR SIZE

       for(int i=0; i < n ;++i){
        // Union the child and the parent nodes if the child Exists (not != -1)
           int lc = leftChild[i];
           int rc = rightChild[i];

           if(lc != -1)
            ds.UnionByRank(i, lc);
           if(rc != -1)
            ds.UnionByRank(i, rc);
       }
    
        int RootNodeCount = 0; //only 1 exist
        for(int i =0 ; i < n ; ++i){
    /*if the ParentNode for a node is itself, it implies that the node is a root. 
     Therefore check if more than one such Node exists
     because in that case it will simply becomes self explanatory that more than one root exists.*/
        if(ds.findUltimateParent(i)== i)
            RootNodeCount++;
        }
        return RootNodeCount == 1;                   // return true if RootNode count == 1 otherwise it returns false.  
    }
};
