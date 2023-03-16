class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //Greedy Approach :- More the Edge is the more wt is assigned 
        long long sum = 0 ; 
        vector<int>adj[n];
        for(auto&edge : roads){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
          //  cout<<adj[i].size()<<" "<<i<<"\n";
             vp.push_back({adj[i].size(),i});
        }
        sort(vp.begin(),vp.end());
        vector<int>val(n,0);
        int value=1;
        for(auto&it :vp){
            val[it.second]=value;
          //   cout<<it.second<<" "<<value<<"\n";
            value++;
        } 
        for(auto&edge : roads){
            sum+=val[edge[1]]+val[edge[0]];
        }
        return sum;
    }
};
