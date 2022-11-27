class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
   vector<pair<int,int>>mp;
int d = 0;

for(auto&it:nums){	
	int diff = abs(it);
  mp.push_back({diff,it});
}

sort(mp.begin(),mp.end());

//1,1 
// 1,1  1,-1

d = mp[0].second;
for(auto&it:mp){
	if(it.first == mp[0].first){
	if(it.second>d) d = it.second;	
	}
}

return d;     
    }
};
