class Solution {
public:
    void combination(int index , int target , vector<int>&ds , vector<vector<int>>&ans ,  vector<int>&arr){
       if(index==arr.size()){
           if(target==0) {
               ans.push_back(ds);
           }
             return;
       } 
        //pick recursion call
        if(arr[index]<=target){
            ds.push_back(arr[index]);
        combination(index,target-arr[index],ds,ans,arr);
            ds.pop_back(); 
        } 
        
        ///not pick recursion call
        combination(index+1,target,ds,ans,arr);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
         vector<int>ds;
        combination(0,target,ds,ans,candidates);
        return ans;
        
    }
};
