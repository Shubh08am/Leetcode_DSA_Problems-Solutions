class Solution {
public:
// Try to be a better version of Yourself --> 31/12/2023 
// wa_tle_re_ac is the process that keeps me going 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //always if given like max , min , sorted see for binary search 
        //apply binary search row wise  --> t.c = O(m*log(n)) m rows * logn for binary search
        for(int i=0;i<matrix.size();i++){
            int low=0,high=matrix[i].size()-1;
            while(low<=high){
                int mid = low+(high-low)/2;

                if(matrix[i][mid] > target) high = mid-1;
                else if (matrix[i][mid] < target) low = mid+1;
                else if (matrix[i][mid]==target) return true;
            }
        }
        return false;
    }
};
