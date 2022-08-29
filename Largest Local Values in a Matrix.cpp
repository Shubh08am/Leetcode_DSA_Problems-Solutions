class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        vector<vector<int>> ans;
        for(int i = 0; i < grid.size() - 2; i++){
            vector<int> v;
            for(int j = 0; j < grid[0].size() - 2; j++){
                int ret = 0;
                for(int ii = i; ii < i + 3; ii++){
                    for(int jj = j; jj < j + 3; jj++){
                        ret = max(ret, grid[ii][jj]);
                    }
                }
                v.push_back(ret);
            }
            ans.push_back(v);
        }
        return ans;
        
        
    }
};
