class Solution {
public:
    
  bool recursion(vector<vector<char>>& board) {
      //traverse the sudoko solver to find empty place
      for(int i=0;i<board.size();i++){
          for(int j=0; j<board[i].size();j++){
              if(board[i][j] == '.'){
                  // than try to insert all values between 1-9
                  for(char ch='1' ; ch<='9' ; ch++){
                      //now,before inserting check whether it is possible to insert that value 
                      if(possible_to_insert(board,i,j,ch)){
                          // if yes insert ch at that position
                          board[i][j] = ch;
                          
                        if(recursion(board) == true){
                            return true; // and go back by returning true
                        }
                          
                          else {
                              board[i][j]='.' ;
                          }
                      }
                  }
                  return false;  //  if(possible_to_insert(board,i,j,ch) == false){
              }
          }
      }
      return true ; // if filled before hand only and not going inside the above conditions
  } 
    
    
bool possible_to_insert(vector<vector<char>>& board,int row,int column,char ch){
    // we will use a single iteration and only 1 loop to check all conditions --> in row , in column , in 3*3 sub-matrix
    
      // if that value ch is present not possible to insert
    for(int i=0;i<9;i++){
      // checking in column
        if(board[i][column] == ch) return false;
        
        // checking in row
        if(board[row][i] == ch) return false;
        
        // // checking in 3*3 sub-matrix
        if(board[3*(row/3)+i/3][3*(column/3)+i%3] == ch) return false;
    }
    
    return true ; // if all 3 condition is obeyed
}
    
    
    void solveSudoku(vector<vector<char>>& board) {
        // LEARNED FROM STRIVER 
        recursion(board);
    }
};
