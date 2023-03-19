class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<int>& vis){
        vis[node] = 1;
        int adjNode = edges[node];
        if(adjNode==-1) return;
        //take shortest path
        if (!vis[adjNode] && dist[adjNode] > dist[node] + 1) {
            //edge wt is 1
            dist[adjNode] = dist[node] + 1;
            dfs(adjNode,edges, dist, vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        //dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
        vector<int> dist1(n, 1e9), dist2(n, 1e9);
        dist1[node1] = dist2[node2] = 0 ; //src node distance 0 
        //visited array helps us to identify wheather we visited to particular node form node1 or not similarly for visited2
        vector<int> vis1(n, 0), vis2(n, 0);
        //calling dfs from both the nodes i.e. node1 and node2
        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);

        for(int currNode = 0; currNode < n; currNode++){
               int currDist =  max(dist1[currNode], dist2[currNode]) ; 

            if(vis1[currNode] && vis2[currNode] && minDist > currDist){
                //update to max distance
                minDist = currDist;
                ans = currNode;//take index of smallest one
            }
        }
        return ans;
    }
};
