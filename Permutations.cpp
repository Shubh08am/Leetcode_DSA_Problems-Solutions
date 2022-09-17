class Solution { 
    private: 
    void find_permutation(vector<int>&nums,vector<int>&freq,vector<vector<int>>&ans,vector<int>&ds){
	
//base case
if(ds.size()== nums.size()){ 
ans.push_back(ds);
	return;
} 

//recursion case
for(int i=0; i<nums.size();i++){

	//if not present in freq
	if(!freq[i]){
		ds.push_back(nums[i]);
		//than mark it in freq so next time we won't include it
		freq[i]=1;
		
		//Recursion call now 
		find_permutation(nums,freq,ans,ds);
		
		//now backtracking time - remove from freq and ds 
		freq[i]=0;
		ds.pop_back();			
				}	
	
	
}


    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
vector<int>ds;
vector<int>freq(nums.size(),0);
find_permutation(nums,freq,ans,ds);
return ans;
    }
};
