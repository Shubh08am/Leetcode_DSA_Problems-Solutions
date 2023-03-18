class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            adj[edges[i]].push_back(i);
        }
        vector<pair<long long int,int>>vp;
        for(int i=0;i<n;i++){
            long long int sum=0;
            for(auto&it:adj[i]){
               sum+=it;
            }
            vp.push_back({sum,-i});
        }
        sort(vp.rbegin(),vp.rend());
        return -vp[0].second;
    }
};
