class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char score = board[i][j] ; 
                if(score=='.') continue;
                for(int k=0;k<9;k++){
                    //row check 
                    if(k!=j && board[i][k]==score) {
                       // cout<<i<<" "<<j<<" "<<k<<"\n";
                        return false;
                    }
                    //col check 
                    if(k!=i && board[k][j]==score) {
                       //  cout<<i<<" "<<j<<" "<<k<<"\n";
                        return false;
                    }
                    //3*3 sub-matrix check 
                    int nr = 3*(i/3)+k/3;
                    int nc = 3*(j/3)+k%3; 
                    if(nr!=i && nc!=j && board[nr][nc]==score) {
                       // cout<<nr<<" "<<nc<<" "<<i<<" "<<j<<" "<<k<<"\n";
                        return false;
                    }
                }
            }
        }
    return true;
    }
};
