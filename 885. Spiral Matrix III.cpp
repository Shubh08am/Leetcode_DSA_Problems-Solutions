class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m ;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>spiral;
        spiral.push_back({rStart,cStart});
        //till now, 1 coordinate used 
        int used=1,move=1; 
        while(used<rows*cols){
 
            //for right movement first [1,2,3...]
            int canMove=move;
            while(canMove--){
                //row remains same column changes
                cStart++;
                //if new position valid take it in spiral order 
                if(isValid(rStart,cStart,rows,cols)){
                     spiral.push_back({rStart,cStart});
                     used++; //another coordinate used 
                }
            }

            //for down movement 
              canMove=move;
            while(canMove--){
                //column remains same row changes
                rStart++;
                //if new position valid take it in spiral order 
                if(isValid(rStart,cStart,rows,cols)){
                     spiral.push_back({rStart,cStart});
                     used++; //another coordinate used 
                }
            }
            //AFTER ONE SET OF RIGHT-DOWN MOVEMENT MOVE INCREASES BY 1 
            move++;
            

            //for left movement 
              canMove=move;
            while(canMove--){
                //row remains same column changes
                cStart--;
                //if new position valid take it in spiral order 
                if(isValid(rStart,cStart,rows,cols)){
                     spiral.push_back({rStart,cStart});
                     used++; //another coordinate used 
                }
            }
            
            //for up movement 
              canMove=move;
            while(canMove--){
                //column remains same row changes
                rStart--;
                //if new position valid take it in spiral order 
                if(isValid(rStart,cStart,rows,cols)){
                     spiral.push_back({rStart,cStart});
                     used++; //another coordinate used 
                }
            }
            //AFTER ONE SET OF LEFT-UP MOVEMENT MOVE INCREASES BY 1 
            move++;
        }
        return spiral;
    }
};
