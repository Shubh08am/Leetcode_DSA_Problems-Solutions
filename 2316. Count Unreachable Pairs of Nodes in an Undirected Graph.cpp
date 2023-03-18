class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<bool>& vis) {
        int cnt = 1;//every component has atleast 1 node therefore cnt as 1
        vis[node] = 1;
        for (int adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                cnt += dfs(adjacentNode, adj, vis);
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
      //3 dfs call -> ex2 -> 12 pair from 1st , 2 pair from 2nd dfs call , 0 from third 
     //3+4+2+3+1+1=14 
        long long pairs = 0;
        long long sizeOfComponent = 0;
        long long nodesRemaining = n;
        vector<int> adj[n];
        vector<bool> vis(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        //component logic
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                sizeOfComponent = dfs(i, adj, vis);
             //   cout<<"sizeOfComponent "<<sizeOfComponent<<"\n";
                pairs += sizeOfComponent * (nodesRemaining - sizeOfComponent);
             //    cout<<"numberOfPairs "<<pairs<<"\n";
                nodesRemaining -= sizeOfComponent;
             //    cout<<"remainingNodes "<<nodesRemaining<<"\n";
            }
        }
        return pairs;
    }
};
