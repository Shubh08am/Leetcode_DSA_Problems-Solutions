class Solution {
public:
    long long int len(long long int n){
        long long int cnt=0;
        if(n<0){
            n*=-10;
        }
        if(n==0) return 1;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>v(m);
        for(int i=0;i<m;i++){
            long long int ans=0;
            for(int j=0;j<n;j++){
                ans=max(ans,len(grid[j][i]));
            }
            v[i]=ans;
        }
        return v;
    }
};
