class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //BRUTE FORCE :- use additional space for zero determination for row and column 
        //OPTIMIZED APPROACH - track zero for each row and column in matrix only using some number  

        vector<pair<int,int>>zero ; 
        int n = matrix.size(), m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) {
                    zero.push_back({i,j}) ;
                }
            }
        }

        for(int i=0;i<zero.size();i++){
            int row = zero[i].first , col = zero[i].second ; 
            for(int l=0;l<m;l++) matrix[row][l]=0;
            for(int k=0;k<n;k++) matrix[k][col]=0;
        }
    }
};
