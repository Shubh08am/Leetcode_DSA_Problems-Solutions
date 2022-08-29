class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int ans = 0 , cnt = 0;

vector<int>hash(256,-1);
int left = 0 , right = 0;
int n = s.size();


while(right < n){
	


	if(hash[s[right]] != -1){
left = max(left , hash[s[right]]+1);
	}

hash[s[right]] = right;

		ans = max(ans,right-left+1);
	right++;
	
}
return ans;    
    }
};
