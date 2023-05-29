class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& mat){
      int n=mat.size() , m=mat[0].size(),rectangle=0,zeroPos=m;
        // count all submatrices with top-left corner at mat[i][j]
       for(int row=i;row<n;row++){
           for(int col=j;col<zeroPos;col++){
            //   cout<<row<<" "<<col<<"\n";
               if(mat[row][col]==1) rectangle++;
               else {
                //   cout<<row<<" "<<col<<" "<<zeroPos<<"\n";
                   zeroPos=col;
                   }
           }
       } 
    return rectangle;
    }
    int numSubmat(vector<vector<int>>& mat) {
       int n=mat.size() , m=mat[0].size(),rectangle=0;

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            rectangle+=solve(i,j,mat);
           }
       }
      return rectangle;
    }
};
