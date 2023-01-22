class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
 int n = grid.size();
 int m = grid[0].size();
 int res=0;
        
for (int i = 0; i < n; i++) {
 sort(grid[i].begin(), grid[i].end() , greater<int>());
}

for (int i = 0; i < m; i++ ){
int r = 0;
 for (int j = 0; j < n; j++) r = max(r, grid[j][i]);
        res += r;
}

       return res;       
    }
};
