class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto&it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<vector<int>>ans(n);
        for(auto&it:edges){ 
         //   cout<<it[0]<<" "<<it[1]<<"\n";
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,vis,adj);//make dfs call 
            //now,traverse in visited as it has marked all visited node from i 
            for(int j=0;j<n;j++){
                //i!=j as we always mark visited for ith node so when i==j we exclude it
                if(vis[j] && i!=j){
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};
