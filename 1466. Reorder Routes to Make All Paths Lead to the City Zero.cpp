class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int&reorder){
        vis[node]=1;
        for(auto&adjNode:adj[node]){
            if(!vis[abs(adjNode)]){ 
                if(adjNode>0) {
                    reorder++;
             //       cout<<node<<" "<<adjNode<<"\n";
                    }
            //   vis[abs(adjNode)]=1;
                dfs(abs(adjNode),vis,adj,reorder);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) { 
         vector<int>adj[n];
         vector<int>vis(n,0);
         int reorder=0; 

    // We are just making an undirected graph, where we are giving (+ve) sign to outgoing
    // edges and pretending that there is also the same incoming edge (or in general the opposite edge)
    // and inserting it into the adj[] list as (-ve) elements.
    // This is done so that the DFS doesn't stop when there are no outgoing edges 
    // (+ve edges) from the current edge. (Because there might be more outgoing edges afterwards)
     
         for(auto&edge : connections){
             adj[edge[0]].push_back(edge[1]);
             adj[edge[1]].push_back(-edge[0]);
         }
        
        dfs(0,vis,adj,reorder);
        return reorder;
    }
};
