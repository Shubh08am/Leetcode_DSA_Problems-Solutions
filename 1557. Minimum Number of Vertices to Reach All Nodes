class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //DAG than think TOPOLOGICAL SORT 
        //If any node doesn't have incoming edge than it can't be visited 
        //see indegree and all those nodes which has indegree 0 must be included 
        //Kahn's Algorithm (Topo Sort Using Bfs) -> don't print topo sort here 

        vector<int>indegree(n,0),ans;
        for(auto&it:edges){
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
