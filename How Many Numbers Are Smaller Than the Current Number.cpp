class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int>ans;
int n=nums.size();
 // o(2) accepted :) --> else map :-:
  for(int i=0;i<n;i++){ 
  int cnt = 0; 
  for(int j=0;j<n;j++){ 
  if(nums[i]>nums[j]) cnt++; 
  } 
  ans.push_back(cnt);
  }
  
return ans;    
    }
};
