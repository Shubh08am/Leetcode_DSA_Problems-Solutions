class Solution {
public:
    int findLHS(vector<int>& nums) {
unordered_set<int>s;
vector<int>dum;
unordered_map<int,int>mp;
int cnt= INT_MIN , ans = 0;

for(auto&it:nums) {
	s.insert(it);
	mp[it]++;
}

for(auto&it:s) dum.push_back(it);

for(auto&it:dum){
	
	int val = it+1;
	if(mp[val]!=0){
		ans = mp[it]+mp[val];
		cnt= max(cnt,ans);
	}
}
if(cnt==INT_MIN) return 0;

return cnt;    
    }
};
