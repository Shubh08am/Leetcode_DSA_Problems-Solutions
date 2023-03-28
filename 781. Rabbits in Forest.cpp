class Solution {
public:
    int numRabbits(vector<int>& answers) {
     map<int,int>mp;
    int ans=0 ;
    for(auto&val:answers) {
	mp[val]++;
     }
     
    for(auto&val:mp) {
	//check not counted multiple times
	int curr = val.first+1;
		ans+=ceil(val.second*1.0/curr)*curr;
	}
    return ans;
    }
};
