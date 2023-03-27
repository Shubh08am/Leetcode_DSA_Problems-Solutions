class Solution {
    private:
    void find_subset(int start_index,vector<int>&individual_subset,vector<vector<int>>&ans,vector<int>&nums){      
        //base case
        if(start_index == nums.size()){
            // we push individual_subset to our ans
            // ex-> [1] pushed to ans 
            // than [2] and so on.          
            ans.push_back(individual_subset);
            return;
        }
        // RECURSION CALL --> (1) INCLUDE , (2)NOT-INCLUDE      
        //pick case --> i.e include case
        // keep adding value from nums to individual_subset
        individual_subset.push_back(nums[start_index]);       
        // than go to next index and call find_subset again.
        find_subset(start_index+1,individual_subset,ans,nums);        
        //backtracking step
        // when we return at that time remove the last added value so that we can go for right recursion call pending      
        individual_subset.pop_back(); 
        //not pick --> i.e not-include case
        // go to next index and call find_subset again.
      find_subset(start_index+1,individual_subset,ans,nums);     
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    // if n is the size of nums --> total subset possible 
    vector<vector<int>> ans; // stores all subset 
    vector<int>individual_subset; // consist of all subset one
    // initially start_index is 0
    find_subset(0,individual_subset,ans,nums); // recursion call  
    return ans;
    }
};
