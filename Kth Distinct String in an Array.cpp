class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;

string ans="";

for(auto&i:arr) mp[i]++;

for(int i=0;i<arr.size();i++){

	if(mp[arr[i]] == 1){		k--;		ans = arr[i];

	}

 if(k==0) break;

}
if(k!=0) return "";
return ans;
    }
};
