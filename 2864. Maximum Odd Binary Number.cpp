class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int o1 = count(s.begin(),s.end(),'1') ; 
        int o0 = s.size()-o0;
        string ans(s.size(),'1') ; 
        for(int i=o1-1;i<s.size()-1;i++) ans[i]='0';
        return ans;
    }
};
