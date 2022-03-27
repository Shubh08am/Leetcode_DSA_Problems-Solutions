class Solution {

    private:

    void answer ( vector<int>nums, vector<vector<int>> & results , int index){

        // base case

if( index >= nums.size()){

    results.push_back(nums);}

        

        

        

        for( int j = index ; j<nums.size();j++){

            swap ( nums[index],nums[j] ) ;

            answer( nums , results, index+1);

            

            // backtracking line

swap(nums[index] , nums[j] ) ;

        }

        

        

    }

public:

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>results;

        int index = 0 ;

        answer (nums, results,index);

        

        return results;

    }

};
