class Solution {
    private:
    int timer=0; //initially,start dfs call and assign tin/low time to every node. We can take any value 0/1 so on

    void dfs(int node , int parent ,vector<int>&vis , vector<int>&tin,vector<int>&low,vector<int>adj[],vector<vector<int>>&bridges){ 
        vis[node]=1; //mark node initially as visited 
        //assign timer to both tin & low for node 
        tin[node] = low[node] = timer ; 
        timer++; //increment for next node 

        for(auto it : adj[node]){
            if(it==parent) {
                cout<<it<<" "<<parent<<"\n";
                continue;
                }
            if(!vis[it]){
                //make a dfs call 
                 dfs(it,node,vis,tin,low,adj,bridges);
        //         cout<<it<<" "<<node<<"\n";
                 //assign low[node] as minimum from adjNode 
                 low[node] = min(low[node] , low[it]) ; 
        // (node) --> (it) --> Now from it we can't reach node if low[it](lowest time to reach adjNode) is more than insertion time of node 
                 if(low[it]>tin[node]){
                     //bridge exist 
                     bridges.push_back({it,node});
                 }
            }
            else if(vis[it]){
                //Same Component no bridge exist but still assign low[node] as minimum from adjNode 
                low[node] = min(low[node] , low[it]) ; 
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) { 
        //T.C -> O(V+2E) [DFS TRAVERSAL] 
        //S.C -> O(V+2E) [FOR ADJACENCY LIST]  + O(3N) [for vis,tin,low]
        
        //undirected graph -> create a adjacency list 
        vector<int>adj[n];
        for(auto& it : connections){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
        }
        //use tin(for insertion time) & Low(for lowest time from adjNode except parent Node)
         vector<int>vis(n,0) , tin(n) , low(n) ; 
        vector<vector<int>>bridges;

         //dfs call :- Initially, -1 is assumed to be parent 
         dfs(0,-1,vis,tin,low,adj,bridges);
         return bridges;
    }
};
