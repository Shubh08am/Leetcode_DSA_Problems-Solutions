class Solution {
public: 
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //Approach-1 
        /*
        vector<vector<int>>adj(n);
        for(auto&edge:roads){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int mx = 0 ;
        for(int i=0;i<n;i++){
            unordered_set<int>s1(adj[i].begin(),adj[i].end());
             for(int j=i+1;j<n;j++){
                unordered_set<int>s2(adj[j].begin(),adj[j].end());
                int val = s1.size()+s2.size();
                if(s2.count(i)) val--; //already i & j are directly connected and we are counting them twice therefore decrease by 1
                mx=max(mx,val);
            }
        }
        return mx;
       */
        //Approach-2
        vector<unordered_set<int>>adj(n);
        
        for (auto& edge: roads) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = adj[i].size() + adj[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if (adj[i].count(j) || adj[j].count(i)) {
                    --network_rank;
                }
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};
