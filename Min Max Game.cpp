class Solution {

public:

    int minMaxGame(vector<int>& nums) {

  

        if(nums.size()==1) return nums[0]; 

        

        

    

while(nums.size()>1){

    vector<int>v ;

int n = nums.size(); 

    

for(int i=0;i<n/2;i++){

    if(!(i&1)){

int m = min(nums[2*i],nums[2*i+1]);

	v.push_back(m);    }

 if (i&1){

int mm = max(nums[2*i],nums[2*i+1]);	

	v.push_back(mm);

 }}

		nums = v ;	 }

return nums[0];

    }

};
