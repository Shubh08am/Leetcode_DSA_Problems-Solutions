class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
  int cnt=0; 
vector<int>res;

sort(nums.begin(),nums.end());
for(int i=1;i<nums.size();i++){
	nums[i]=nums[i]+nums[i-1];
}

/*for(auto i:nums) cout<<i << " ";
cout<<endl;*/
	for(int j= 0;j<queries.size();j++){
	for(int i= 0;i<nums.size();i++){
		if(queries[j]>=nums[i]) {cnt++;}
    }
	
			//cout<<cnt<< "\n";
			res.push_back(cnt);
		cnt = 0;	
	
} 

return res;      
    }
};
