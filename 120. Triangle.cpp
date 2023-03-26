class Solution {
public: //Remeber the past else you will be condemned to do it 
    int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        //base case 
          int n = triangle.size(); 
        if(row==n-1) return triangle[row][col] ;
        if(dp[row][col]!=-1) return dp[row][col];
        int down = triangle[row][col] + solve(row+1,col,triangle,dp);
        int diagonal = triangle[row][col] + solve(row+1,col+1,triangle,dp); 
      //  cout<<row<<" "<<col<< " "<<min(down,diagonal) << "\n";
        return dp[row][col]= min(down,diagonal) ; 
    } 
    int minimumTotal(vector<vector<int>>& triangle) {
        //minimum path sum - move down or diagonal 
        int n = triangle.size() ;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
};
