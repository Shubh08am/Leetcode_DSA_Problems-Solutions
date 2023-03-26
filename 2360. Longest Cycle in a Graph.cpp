class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<int>&vis,vector<int>&edg,vector<int>&dist,int &cycle,int currDist){
        if(node!=-1){
            if(!vis[node]){
                vis[node]=1;
                edg[node]=1;
                dist[node]=currDist;
                dfs(edges[node],edges,vis,edg,dist,cycle,currDist+1);
            }
            else if(edg[node]){
                cycle=max(cycle,currDist-dist[node]);
            }
            edg[node]=0;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0),edg(n,0),dist(n,0);
        int cycle =-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,edg,dist,cycle,0);
            }
        }
        return cycle;
    }
};
