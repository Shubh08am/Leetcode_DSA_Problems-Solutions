class Solution {
public:
   //If cycle is present
    bool CyclePresent(vector<int> adj[],int n){
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto adjNode : adj[i]){
                inDegree[adjNode]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
            q.push(i);
        }
        vector<int> topoSort;
        while(!q.empty()){
            auto node=q.front();
             q.pop();
            topoSort.push_back(node);
            for(auto adjNode : adj[node]){
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0)
                q.push(adjNode);
            }
        }
        return topoSort.size()!=n;
    }

    void dfs(int node,string &colors,vector<int> adj[],int &res,vector<int> &vis,vector<vector<int>> &dp){
        vis[node]=1;
        int maxi=1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,colors,adj,res,vis,dp);
            }
            for(int i=0;i<26;i++){
                dp[node][i]=max(dp[node][i],dp[adjNode][i]);
                maxi=max(maxi,dp[node][i]);
            }
        }
        //store the frequency as well
        dp[node][colors[node]-'a']++;
        maxi=max(maxi,dp[node][colors[node]-'a']);
        res=max(res,maxi);
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        if(CyclePresent(adj,n)){
        return -1;
        }

        vector<vector<int>> dp(n,vector<int>(26,0));
        int res=1,maxi=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,colors,adj,res,vis,dp);
            }
        }
        return res;
    }
};
