class Solution {
public:
    //if reach at end of s than only possible 
    void solve(int ind,string curr,string s, vector<string>& wordDict ,vector<string>&ans,unordered_map<string,int>&freq){
        int n = s.size();
        if(ind==n){
            curr.pop_back(); // last space removed 
            ans.push_back(curr) ; 
            return;
        }
        string p="";
        int flag = 0 ; 
        for(int i=ind;i<n;i++){
            p+=s[i] ; 
            if(freq[p]>0){
                solve(i+1,curr+p+' ',s,wordDict,ans,freq) ; 
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_map<string,int>freq;
        for(auto it : wordDict)  freq[it]++; 
        solve(0,"",s,wordDict,ans,freq) ; 
        return ans;
    }
};
