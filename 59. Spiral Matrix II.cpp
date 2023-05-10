class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // first Row -> Last Column -> last Row -> first Column 
        vector<vector<int>>spiral(n,vector<int>(n));

        int startingRow = 0 , lastRow = n-1 ; 
        int startingCol = 0 , lastCol = n-1 ; 
        int value=1;

        while(value<=n*n){
                //for startingRow 
                int i = startingCol ;
                while(i<=lastCol){
                    spiral[startingRow][i]=value;
                    value++;i++;
                }
            //move to nextRow now 
            startingRow++;

             //for lastCol 
                  i = startingRow ;
                while(i<=lastRow){
                    spiral[i][lastCol]=value;
                    value++;i++;
                }
            //move to PrevCol now 
            lastCol--;

              //for lastRow 
                  i = lastCol ;
                while(i>=startingCol){
                    spiral[lastRow][i]=value;
                    value++;i--;
                }
            //move to prevRow now 
            lastRow--;

             //for startingCol 
                  i = lastRow ;
                while(i>=startingRow){
                    spiral[i][startingCol]=value;
                    value++;i--;
                }
            //move to nextCol now 
            startingCol++;
        }
        return spiral;
    }
};
