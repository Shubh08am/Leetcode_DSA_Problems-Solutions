class Solution {
public:
     
        int sc(int n,vector<int>adj[]){
       int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, (int)(1e9));
        vector<int> par(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int child : adj[x]) {
                if (dist[child] == (int)(1e9)) {
                    dist[child] = 1 + dist[x];
                     par[child] = x;
                    q.push(child);
                }
                 else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }
 
    if (ans == INT_MAX) return -1; //no cycle
     return ans;
}
 
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n] ; 
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ; 
             adj[it[1]].push_back(it[0]) ; 
        }
       return sc(n,adj) ; 
        
    }
};
