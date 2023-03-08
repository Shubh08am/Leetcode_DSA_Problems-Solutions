class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //simple bfs , dfs works without visiting restricted nodes 
        queue<int>q;
        vector<int>vis(n,0),v(n,0);
        int Reachable = 0;
        //create adjacency list 
       vector<vector<int>>adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //mark all restricted node as visited in v & vis both
        for(auto it : restricted) {
            v[it]=1;
            vis[it]=1;
            }
        q.push(0);
        while(!q.empty()){
            int node = q.front(); 
        //  cout<<node<<"\n";
            q.pop();
            //for restricted node
            if(v[node]) continue;
            //see neighbour 
            for(auto adjNode : adj[node]){
                      if(!vis[adjNode]){
                          Reachable++;
                    //    cout<<adjNode<<"adj\n";
                         vis[adjNode]=1;
                         q.push(adjNode);
                      }
            }
        }
        return Reachable==0?1:Reachable;
    }
};
