class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,set<int>>mp;
        for(auto it : adjacentPairs) {
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        map<int,int>vis;
        vector<int>ans;
        queue<int>q;
        for(auto it : mp){
            if(it.second.size()==1){
                q.push(it.first);
                vis[it.first]=1;
                break;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &adjNode:mp[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode]=1;
                }
            }
        }
    return ans;
    }
};
