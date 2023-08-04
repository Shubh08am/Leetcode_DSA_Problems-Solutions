class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end()) ; 
      //  for(auto it : strs) cout<<it<<" ";
        int n = strs.size() ; 
        string curr = strs[0] , last = strs[n-1] , s=""; 
        for(int i=0;i<curr.size();i++){
                 if(curr[i]==last[i]) s+=curr[i] ; 
                 else break;
        }
    return s;
    }
};
