class Solution {
public:
    int dfs(int node,vector<int>adj[],vector<int>&ans,vector<int>& quiet){
         if(ans[node] != -1) return ans[node]; //already visited part
        
        ans[node] = node;
        for(auto&adjNode:adj[node]){
        int ans_adjnode = dfs(adjNode,adj,ans,quiet);
            
            //if we get more quietest person we update answer
            if(quiet[ans_adjnode] < quiet[ ans[node]]) {
                ans[node] = ans_adjnode;
            }
         }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //DAG GRAPH AS ONE DIRECTION RELATIONSHIP -> TOPOLOGICAL SORT 
        // richer[i] = [ai, bi] --> bi -> ai 
        // ex:- 2>1 -> 1>0 i.e 2>0 and quietness fore 2 is 2 so on take least quietness for 0 and so on 
      /*  //Approach -1 :- USING DFS 
        int n = quiet.size(); 
        vector<int>adj[n];
        vector<int>ans(n,-1);
        for(auto&edge : richer){
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
             dfs(i,adj,ans,quiet);
            }
        return ans;
        */

        //Approach -2 :- USING BFS 
        int n = quiet.size();
        vector<int> indegree(n,0), ans(n,INT_MAX);
        vector<int>adj[n];
        queue<int> q;
        
        for(auto&edge : richer){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
       
         for(int i=0;i<n;i++){
            ans[i]=i;
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto it : adj[curr]){
                //if parent node have more money is quieter , update
                if(ans[it] == INT_MAX || quiet[ans[it]] > quiet[ans[curr]])
                    ans[it] = ans[curr];
                    indegree[it]-=1;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
};
