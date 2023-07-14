class Solution {
public:
     /*
        Time Complexity : O(n!)
        Space Complexity : O(n)
    */
    void solve(int col,int n,vector<string>&ChessBoard,vector<vector<string>>&ans,vector<int>&left,vector<int>&leftDiagonal,vector<int>&rightDiagonal){
        if(col==n){
            ans.push_back(ChessBoard);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && leftDiagonal[row+col]==0 && rightDiagonal[n-1+col-row]==0){
                ChessBoard[row][col]='Q';
                left[row]=1;
                leftDiagonal[row+col]=1;
                rightDiagonal[n-1+col-row]=1;
                solve(col+1,n,ChessBoard,ans,left,leftDiagonal,rightDiagonal);
                ChessBoard[row][col]='.';
                left[row]=0;
                leftDiagonal[row+col]=0;
                rightDiagonal[n-1+col-row]=0;
            }
        }
    }
    int solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>ChessBoard(n); 
        string element(n,'.') ; 
        for(int i=0;i<n;i++) ChessBoard[i] = element; 
        vector<int>left(n,0),leftDiagonal(2*n-1,0),rightDiagonal(2*n-1,0);
        solve(0,n,ChessBoard,ans,left,leftDiagonal,rightDiagonal);
        return ans.size();
    }
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};
