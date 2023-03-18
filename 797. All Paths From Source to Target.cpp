 class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<int>& path,vector<vector<int>>&ans) {
         // add current node to path
        path.push_back(i);          
        // valid path found                 
        if(i == graph.size()-1) ans.push_back(path);       
        else {
                for(auto child : graph[i])  
                dfs(graph, child, path,ans);
                } 
        // backtrack
        path.pop_back();                             
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int> path;
        dfs(graph, 0, path,ans);
        return ans;
    }
};
