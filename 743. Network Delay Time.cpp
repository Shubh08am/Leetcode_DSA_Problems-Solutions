class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //try dijkstra's Algorithm or floyd warshall (distance from single to every node) 
    vector<pair<int,int>>adj[n+1];
    //  vector<vector<int>>adj[n+1];
        for(auto&edge : times){
      //    cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<"\n";
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        //distance of src marked as 0 
       
        dist[k]=0;
        //Initially,in pq src along with distance as 0 pushed 
        pq.push({0,k}); 
        while(!pq.empty()){ 
             int dis = pq.top().first;
            int node = pq.top().second;
        //    cout<<dis<<" "<<node<<"\n";
            pq.pop();
             
             //go inside adj list 
             for(auto&it : adj[node]){
                int adjNode = it.first ;
                 int edgeWt = it.second ; 
             //  int adjNode = it[0] ;
             //   int edgeWt = it[1] ; 
                 //apply condition 
                 if(dis+edgeWt<dist[adjNode]){
                     dist[adjNode]=dis+edgeWt;
                     pq.push({dis+edgeWt,adjNode});
                 }
             }
        } 
   //     for(auto&val:dist) cout<<val<<" ";
         int ans=0;
        //if any node not reachable than it would have value as 1e9 else return max value to reach last node (n)
        for(int i=1;i<=n;i++) {
            if(dist[i]==1e9) return -1;
             ans = max(ans,dist[i]);
        }
        return ans;
    }
};
