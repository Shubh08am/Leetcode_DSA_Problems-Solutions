/*
10 <= time[j], maxTime <= 100 By this constraint, there are at most 10 nodes in a path.
There are at most four edges connected to each node
Based on the aforementioned constraints, the brute force approach runs in O(4^10) = O(2^20) 
*/
class Solution {
public:
    int dfs(int node, vector<vector<int>>adj[],vector<int>& vis,vector<int>& values,int maxTime,int timeTaken , int curr_quality){
        int maxQuality = 0 ; 
        if(node==0){
            maxQuality=max(maxQuality,curr_quality);
        }
        vis[node]++;
        for(auto&it:adj[node]){
            int time = it[1];
            int adjNode =it[0];
            if(timeTaken+time<=maxTime){
                int score = curr_quality+(vis[adjNode]==0?values[adjNode]:0) ;
                maxQuality=max(maxQuality,dfs(adjNode,adj,vis,values,maxTime,timeTaken+time,score));
            } 
        }
        vis[node]--;
        return maxQuality;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        /*
        visit a node multiple time with given time bound i.e maxTime
        Explore all the Possible path and take max quality one 
        */
        int n = values.size(),maxQuality=0;
        vector<vector<int>>adj[n];
        vector<int>vis(n,0);
        for(auto&it:edges){
            adj[it[0]].push_back({it[1],it[2]}) ;
            adj[it[1]].push_back({it[0],it[2]}) ; 
        }
        return dfs(0,adj,vis,values,maxTime,0,values[0]);
    }
};
