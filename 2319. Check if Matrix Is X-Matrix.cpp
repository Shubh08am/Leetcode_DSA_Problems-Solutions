class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j && grid[i][j]==0) return 0;
                if(i==m-j-1 && grid[i][j]==0) return 0;
                if(i!=j && i!=m-1-j && grid[i][j]!=0) return 0;
            }
        }
    return 1;
    }
};
