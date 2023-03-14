class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row =  matrix.size() , column = matrix[0].size(); 
        
        int startingRow = 0 , endingRow = row-1;
        int startingColumn = 0 , endingColumn = column-1;
        int total_Element = row*column;
        int cnt=0;
        vector<int>spiral;

        while(cnt<total_Element){
            //print starting row 

            for(int i=startingColumn; cnt<total_Element and i<=endingColumn;i++){
              spiral.push_back(matrix[startingRow][i]);
              cnt++;
            }
            startingRow++; //go to next Row

           

              //print ending column 

            for(int i=startingRow;  cnt<total_Element and i<=endingRow;i++){
              spiral.push_back(matrix[i][endingColumn]);
              cnt++;
            } 
            endingColumn--; //go to prev column 
            

             //print ending row 

            for(int i=endingColumn;  cnt<total_Element and i>=startingColumn;i--){
              spiral.push_back(matrix[endingRow][i]);
              cnt++;
            }
            endingRow--; //go to prev row  
            
            //print starting  Column 

            for(int i=endingRow;  cnt<total_Element and  i>=startingRow;i--){
              spiral.push_back(matrix[i][startingColumn]);
              cnt++;
            }
             startingColumn++; //go to next column


        }
         return spiral;
    }
};
