class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int>adjacent[n];
        for(auto v:edges){
            adjacent[v[0]].push_back(v[1]);
            adjacent[v[1]].push_back(v[0]);
        }
        vector<int>visit(n,0);
        visit[source]=1;
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto v:adjacent[curr]){
                if(!visit[v]){
                    q.push(v);
                    visit[v]=1;
                }
            }
        }
        return visit[destination]==1;      
    }
};
