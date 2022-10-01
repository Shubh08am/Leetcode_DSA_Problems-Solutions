class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
     long long int sum=0;
int n=nums.size();

for(int i=0;i<n;i++){	
int curr = nums[i]; int curr_no = nums[i]; 

for(int j=i;j<n;j++){	
 curr = max((int)curr,nums[j]);
  curr_no = min(curr_no,nums[j]);
 sum+=curr-curr_no;
}}

return sum;   
    }
};
