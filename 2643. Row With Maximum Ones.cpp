class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<pair<int,int>>vp;
        int n=mat.size(); 
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            int one=0;
            for(int j=0;j<m;j++){
                one+=mat[i][j]==1;
            }
            vp.push_back({one,-i});
        }
        sort(vp.rbegin(),vp.rend());
        return {-vp[0].second,vp[0].first};
    }
};
