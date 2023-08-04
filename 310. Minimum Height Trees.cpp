class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // first find min height of tree by taking each node -> root needs to be returned for all min height tree 
        vector<int>indegree(n,0),ans; 
        vector<int>adj[n] ; 
        if(n==1) ans.push_back(0) ;
        for(auto&it : edges){
            int u = it[0] , v = it[1] ;
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
            indegree[u]++;
            indegree[v]++;
        }

        queue<int>q; 
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i) ; 
        }

        while(!q.empty()){
            int sz = q.size();
            ans.clear();
            while(sz--){
                int node = q.front() ;
                ans.push_back(node); 
                q.pop() ; 
                for(auto&it:adj[node]){
                    indegree[it]--; 
                    if(indegree[it]==1) q.push(it) ; 
                }
            }
        }
    return ans;
    }
};
