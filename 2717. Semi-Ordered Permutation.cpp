class Solution {

public:

    int semiOrderedPermutation(vector<int>& nums) {

        int n=nums.size() , o=0,m=0;

for(int i=0;i<n;i++){

	if(nums[i]==1) o=i;	if(nums[i]==n) m=i;

	

}

if(m<o) return o+n-m-2;

return o+n-m-1;

    }

};
