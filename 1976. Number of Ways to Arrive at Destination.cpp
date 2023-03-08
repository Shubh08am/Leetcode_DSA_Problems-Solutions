class Solution {
public: 
    int mod = (int) (1e9+7) ;
    int countPaths(int n, vector<vector<int>>& roads) {
        //{distance,Node}
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        vector<long>dist(n,LONG_MAX),ways(n,0);
       // vector<vector<vector<long>>>adj(n); 
        vector<pair<long,long>>adj[n] ; // other way to create adjacency list
        //Undirected Graph
        for(auto it : roads){
         adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});
        }
        //src is 0 
        dist[0]=0;
        ways[0]=1; //we can reach src in only 1 ways 
        pq.push({0,0}); 
    
        //Apply Dijkstra's Algorithm 
        while(!pq.empty()){
            auto it = pq.top() ; 
            pq.pop() ; 
            long dis = it.first , node = it.second;

            for(auto i : adj[node]){ 
                // long adjNode =i[0] , edgeWt =i[1] ; 
                 //if using adj -> pair 
                 long adjNode =i.first , edgeWt =i.second; 
                //condition Case 1:- First time visit with Shortest distance 
                 if( dis + edgeWt  < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt ; 
                    pq.push({dis + edgeWt,adjNode});
                    //update ways to reach adjNode from node to be as ways[node] as first time visited adjNode 
                    ways[adjNode] = ways[node]; 
                }
                //condition Case 2:- visiting adjNode again with Shortest distance update ways to reach adjNode
                else if(dis + edgeWt == dist[adjNode]){
                    //update ways to reach adjNode from node to be as ways[adjNode] + ways[node] as we already visited adjNode 
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod; 
                }
            }
        }
      //  for(auto it : adj) for(auto x : it) for(auto xx : x) cout<<xx<<" ";
        return ways[n-1]%mod;
    }
}; 
