class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<double>>adj[n];
        int i=0;double res=0;
        vector<double>dist(n,0);
        for(auto&it:edges){ 
           //  cout<<it[0]<<" "<<it[1]<<" "<<succProb[i]<<"\n";
             adj[it[0]].push_back({(double)it[1],succProb[i]});
             adj[it[1]].push_back({(double)it[0],succProb[i]});
            i++;
        }
     priority_queue<pair<double,double>>pq;
      pq.push({1.0,start});
      dist[start]=1.0;
  
    while(!pq.empty()){
    int node = pq.top().second;
    double dis = pq.top().first ;
     pq.pop(); 
     //return here only or at last return end distance
  /*   if(node==end) {
        //take max one 
        return dis;
    } */
   // cout<<dis<<"\n";
    for(auto&it:adj[node]){
        int adjNode = it[0] ; 
        double edgeWt =   it[1] ;
        double val = (double)dis*edgeWt*1.0;  

     //   cout<<adjNode<<" "<<edgeWt<<" "<<val<<"\n";
          
         if(val>dist[adjNode]){
          pq.push({val,adjNode});
          dist[adjNode]=val;
         }   
     }
    }
    return dist[end] ; 
    }
};
