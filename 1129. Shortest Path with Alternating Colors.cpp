class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj[n];
        //1 indicates red edge
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1], 1});
        }
        //2 indicates blue edge
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1], 2});
        }

        vector<int> dist(n, -1);
        vector<vector<int>>vis(n, vector<int>(3,0));
        queue<pair<int,pair<int,int>>> q;
        // {node, steps, color}
        q.push({0, {0, 0}}); 
        dist[0] = 0; //mark src node distance 0 
        
        vis[0][1] = vis[0][2] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second.first;
            int prev_color = q.front().second.second;
            q.pop();

            for(auto it : adj[node]) {
                int adj_node = it[0];
                int color = it[1];
                if(color == prev_color) continue;
                if(!vis[adj_node][color]){
                    vis[adj_node][color] = 1;
                    if(dist[adj_node] == -1) {
                        dist[adj_node] = 1 + steps;
                    }
                    q.push({adj_node, {1 + steps, color}});
                }
            }
        } 
        return dist;
    }
};
