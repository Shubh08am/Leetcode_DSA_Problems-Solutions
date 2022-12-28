class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
  vector<int>v;
int zero=0;
int val = 0; 
/*        
if(nums[nums.size()-1]!=nums[nums.size()-2]){
if(nums[nums.size()-1]!=0){
		val = nums[nums.size()-1];
}
}
*/
for(int i=0;i<nums.size()-1;i++){
	if(nums[i]==nums[i+1] && nums[i]!=0){
		v.push_back(2*nums[i]);
		nums[i+1]=0;
	}	
	
	else if(nums[i]!=0){
		v.push_back(nums[i]);
	}
	
} 
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
if(nums[nums.size()-1]!=0){
		val = nums[nums.size()-1];
}} 
        
if(val!=0)
v.push_back(val);

        
for(auto&it:nums){ 
  //  cout << it << " " ;
	if(it==0) zero++;
}
//cout<<"\n"; 
  /*      for(auto&it:v){
	cout<< it << " ";
}
cout<<endl;
*/
while(zero){
v.push_back(0);	 
    zero-=1;
}
return v;      
    }
};
