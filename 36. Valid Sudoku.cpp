class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int sub[3][3][9] = {0};
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)  {
            if(board[i][j]=='.') {
            continue;
            }

            int check = board[i][j]-'1';
            if(col[check][j]++ || row[i][check]++ || sub[i/3][j/3][check]++){
            return false;
            }
                
        }
    }
    
    return true;
    }
};
