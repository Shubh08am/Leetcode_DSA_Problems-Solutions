#define ll long long
class Solution {
public:
    ll dp[100001][16];
    ll dfs(int node,int parent,vector<ll>adj[],vector<int>& coins, int k,ll operation){
        if(operation>15) return 0;
        ll &val= dp[node][operation];
        if(val!=-1) return val;
        ll cn = coins[node]/(1<<operation) ;
        ll first = cn-k ; 
        ll second = cn/2 ; 
        ll op1=first , op2=second ; 
        
        for(auto &adjNode : adj[node]){
            if(adjNode!=parent){
                op1+=  dfs(adjNode,node,adj,coins,k,operation) ; 
                op2+=  dfs(adjNode,node,adj,coins,k,operation+1) ; 
            }
        }
    return val=max(op1,op2) ; 
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size() ; 
        vector<ll>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        memset(dp,-1,sizeof(dp));
      return dfs(0,-1,adj,coins,k,0);  
    }
};
