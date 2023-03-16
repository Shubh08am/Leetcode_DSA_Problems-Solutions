class Solution {
public: 
    int dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&vals,int k){
        vis[node]=1;
        int ans=INT_MIN , currSum=0;
        priority_queue<int>pq;
        
        for(auto it : adj[node]){
                 pq.push(vals[it]);//push all values in pq of adjNode
            if(!vis[it]){
                  ans=max(ans,dfs(it,vis,adj,vals,k));
            }
        } 
        //take atmost k nodes sum 
         currSum=vals[node];
         //take atmost k nodes sum 
        while(k>0 && !pq.empty()){ 
           if(pq.top()>0){ //only taking +ve values
               currSum+=pq.top();
               k--;
               }
            pq.pop();
        }
      //  cout<<currSum<<"\n";
        int maxi = max(ans,currSum);
        return maxi;
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        //DFS+PQ 
        int n=vals.size() , ans=INT_MIN;
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]) ;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=max(ans,dfs(i,vis,adj,vals,k));
            }
        }
        return ans;
    }
};
