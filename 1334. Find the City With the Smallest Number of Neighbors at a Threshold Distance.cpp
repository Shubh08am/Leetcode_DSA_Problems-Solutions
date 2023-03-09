class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Apply, dijsktra on every node or use floyd Warshall Algorithm 
        int city=0 , minCity=1e9 , cityNo=0;
        vector<vector<int>>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
        vector<int> dist(n, 1e9);
        dist[i] = 0;
        //{dist,node}
        pq.push({0,i});
        while(!pq.empty()){
            int dis = pq.top().first ,  node= pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it[0] , edgeWt = it[1];
               if(dis+edgeWt<dist[adjNode]){
                   dist[adjNode]=dis+edgeWt;
                   pq.push({dis+edgeWt,adjNode});
               }
            } 
        }    
        //now,see for reachable city 
        for(int j=0;j<n;j++){
     //      cout<<dist[j]<<" "; 
         //now,see reachable city with distance <= distanceThreshold 
         // i!=j as reaching same city from same city already takes 0
        if(dist[j]<= distanceThreshold && i!=j) city++;
        }
   //    cout<<"\n";
      //take min reachable city && cityNo is maximum 
   //  cout<<minCity<<" "<<city<<" "<< cityNo<<"\n";
  // cout<<i<<"\n";
      if(minCity>=city) {
          minCity=city;
          cityNo = i;
          }
        //   cout<<minCity<<" "<<city<<" "<< cityNo<<"\n";
        //make city=0 now for next node which start calculation again for reachable city 
      city=0;
     }
     return cityNo;
    }
};
