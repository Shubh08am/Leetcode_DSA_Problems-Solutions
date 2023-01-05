class Solution {
public:
    int distinctAverages(vector<int>& nums) {
set<double>unique;
int size = nums.size();
int i=0,j=size-1;

sort(nums.begin(),nums.end());

while(i<j){	
double val = (nums[i]+nums[j])/2.0;
unique.insert(val);		
i++;
j--;	
}

return unique.size();        
    }
};
