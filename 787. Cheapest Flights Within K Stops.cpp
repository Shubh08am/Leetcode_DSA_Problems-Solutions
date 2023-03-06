class Solution {
public:
//T.C = O(E*K+V)
//S.C = O(E*K+V)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n] ; 
        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q; 
        //{stop,{node,distance/cost}}  
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        //src distance is 0 
        dist[src]=0;

        //Apply Dijkstra's Algorithm 
        while(!q.empty()){ // RUNS FOR O(V)
            auto it = q.front() ; 
            q.pop();
            int stop = it.first ; 
            int node = it.second.first , cost = it.second.second ; 

            //Exceeded min no. of stop i.e k 
            if(stop > k) continue; 
            for(auto i : adj[node]){ // RUNS FOR O(E*K)
                int adjNode = i.first , edgeWt = i.second ;
                //condition 
                if(cost + edgeWt < dist[adjNode]){
                    dist[adjNode] = cost + edgeWt ; 
                    q.push({stop+1,{adjNode,cost + edgeWt}});
                }
            }
        }
        //if not able to reach destination return -1 else return dist[dst]
        return dist[dst]==1e9?-1:dist[dst] ;
    }
};
