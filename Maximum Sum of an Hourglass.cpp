class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        // _ _ _ 
        //   _
        // _ _ _
        int n = grid.size();
        cout<<n<<endl;
        int s = 0; int m =INT_MIN;
                    int mm = grid[0].size();

        for(int i=0;i<n-2;i++){
            for(int j=0;j<mm-2;j++){
s = (grid[i][j]+grid[i][j+1]+grid[i][j+2])+(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2])+(grid[i+1][j+1]);
 
            
            m = max(m, s);          
            
        }}
        return m;
    }
};
