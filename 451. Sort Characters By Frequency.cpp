class Solution {
public:
    string frequencySort(string s) {
string ans;
map<char,int>freq;
for(auto it : s) freq[it]++;

vector<pair<int,char>>res;

for(auto it : freq){
	res.push_back({it.second,it.first});
    }

    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());

    for(auto it : res){
    	while(it.first--){
        	ans.push_back(it.second);
            	}
                }

                return ans;
    }
};
