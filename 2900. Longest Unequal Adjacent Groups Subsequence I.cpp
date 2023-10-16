class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
        vector<string>ans; 
        int prev=-1;
        for(int i=0;i<n;i++){
            if(prev!=g[i]){
                ans.push_back(w[i]); 
                prev=g[i];
            }
        }
    return ans;
    }
};
