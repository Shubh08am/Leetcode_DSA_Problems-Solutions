class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) ans+=mat[i][j];
                else if(i==n-1-j) ans+=mat[i][j];
            }
        }
    return ans;
    }
};
