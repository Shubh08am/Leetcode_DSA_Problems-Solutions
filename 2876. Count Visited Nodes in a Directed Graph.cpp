class Solution {
public:
    // T.C -> O(2*N)
    void dfs(int node,vector<int>& edges,vector<int>& vis,vector<int>& values){
            int adjNode=edges[node];
            vis[node]=1;
            if(!vis[adjNode])  {
                dfs(adjNode,edges,vis,values);
            }
        values.push_back(node);
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        /*
        Node involved in cycle = length of cycle 
        Now, each edges that go has 2 option 
        [1] Go, on un-visited node 
        [2] Go, on visited node
        if un-visited node its value = 1 + next node from it 
        */
        //APPLY TOPOLOGICAL SORT FOR NODE NOT INVOLVED IN CYCLE 
        int n = edges.size() ; 
        vector<int>indegree(n,0),topo,vis(n,0),times(n,0);
        queue<int>q;
        for(auto&it : edges){
            indegree[it]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            vis[node]=1;
            indegree[edges[node]]--;
            if(indegree[edges[node]]==0) q.push(edges[node]);
        }
        
        //APPLY DFS FOR NODE INVOLVED IN CYCLE -> AND FIND THE LENGTH OF CYCLE 
        for(int i=0;i<n;i++){
            if(!vis[i]){ 
                vector<int>values;
                dfs(i,edges,vis,values);
                int cycleLen = values.size();
                //Node involved in cycle = length of cycle  
                for(auto&cycleNode : values) times[cycleNode]=cycleLen;
            }
        }
     reverse(topo.begin(),topo.end()); 
        
        //[2] Go, on visited node and node value = 1 + next node from it -> times[edges[unvisitedNode]]
        for(auto&unvisitedNode : topo) {
          //  cout<<unvisitedNode<<" " << edges[unvisitedNode] << "\n";
           times[unvisitedNode]=1+times[edges[unvisitedNode]];
        }
        
    return times;
    }
};
