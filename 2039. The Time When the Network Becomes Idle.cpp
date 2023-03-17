class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>>adj(n);
        vector<int>vis(n,-1);

        // create adjacency list
        for(auto& it: edges) { 
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //single source shortest path using bfs for every data server
        queue <int> q;
        q.push(0);
        vis[0] =0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto& adjNode: adj[node]) {
                if(vis[adjNode]==-1) { // if not visited.
                    vis[adjNode] = vis[node] +1 ; // calc time for child node
                    q.push(adjNode);
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i<n; i++){
             int d = vis[i];
             int temp = 2*d;
             
             if(2*d > patience[i]){
                if((2*d)%patience[i]==0)
                temp=4*d-patience[i];
                else
                    temp=4*d-(2*d)%patience[i];   
            }
            res = max(res,temp);
			
        }
        return res+1; // since till res time all messages has beed arrived so +1
    }
};
