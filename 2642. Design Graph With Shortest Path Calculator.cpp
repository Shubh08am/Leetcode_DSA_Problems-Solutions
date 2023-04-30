class Graph {
public:
    //Dijkstra's Algorithm
    vector<pair<int,int>>adj[101];
    int m;
    Graph(int n, vector<vector<int>>& edges) {
         //{node,weight}
        m=n;
         for(auto&it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    void addEdge(vector<int> edge) {
           adj[edge[0]].push_back({edge[1],edge[2]});
    }
    int shortestPath(int node1, int node2) {
        //Shortest path from node 1 to node 2
        vector<int>dist(m,1e9);
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         pq.push({0,node1});
         dist[node1]=0;
        
         while(!pq.empty()){
            int node = pq.top().second , dis = pq.top().first; 
             pq.pop();
             for(auto it:adj[node]){
                 int adjNode =  it.first, edgeWt = it.second; 
                 if( dis+edgeWt < dist[adjNode]){
                     dist[adjNode] = dis+edgeWt;
                     pq.push({dist[adjNode],adjNode});
                 }
             }
         }
          return dist[node2]==1e9?-1:dist[node2];
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
