class Solution {
public: 
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&ans){
        vis[node]=1;
        set<int> st;
        //insert all neighbour value in set so that adjacentNode doesn't have same value
        for(auto neighbour : adj[node]){ 
           cout<<node<<" "<<neighbour<<" "<<ans[neighbour]<<"\n";
            st.insert(ans[neighbour]);
        }
        //At max 3 edge assign all different value using hashing or set data structure
        for(int i = 1;i <= 4;i++){ 
            //if not present use that value from 1 to 4
            if(!st.count(i)){
                ans[node] = i;
                break;
            }
        } 
         cout<<node<<" "<<ans[node]<<"\n";
          for(auto&adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,vis,adj,ans);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n+1];
        for(auto&edge:paths){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n+1,0),ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,ans);
            }
        }
        ans.erase(ans.begin());//as we don't need 0th index
        return ans;
    }
};
