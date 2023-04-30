class Solution {
public:
    int maxDivScore(vector<int>& n, vector<int>& d) {
        vector<pair<int,int>>vp;
        int m= n.size() , x=d.size();
        
        for(int i=0;i<x;i++){
            int div=0;
            for(int j=0;j<m;j++){
                div+=n[j]%d[i]==0;
            }
            vp.push_back({div,-d[i]});
        }
        sort(vp.rbegin(),vp.rend());
        return -vp[0].second;
        
    }
};
