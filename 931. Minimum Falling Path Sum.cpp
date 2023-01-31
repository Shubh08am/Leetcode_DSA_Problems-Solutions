class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&nums) {
        int row=nums.size();
        int column=nums[0].size();
        for(int i=1;i<row;i++){
            for(int j=0;j<column;j++){
                if(j==0) {
               //Leftmost or first column
                nums[i][j]+=min(nums[i-1][j],nums[i-1][j+1]);
                }
                
                else if(j==column-1){
                       //Rightmost or last column
            nums[i][j]+=min(nums[i-1][j],nums[i-1][j-1]);  
                }
                else {
                    //Remaining cases
                 nums[i][j]+= min({nums[i-1][j],nums[i-1][j+1],nums[i-1][j-1]}); 
                }
            }
        }
        int sum=INT_MAX;
        for(int i=0;i<column;i++){
            //Last row scanning
            sum=min(sum,nums[row-1][i]); 
        }
        return sum;
    }
};
