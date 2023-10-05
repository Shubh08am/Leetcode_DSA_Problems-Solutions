class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size() , absent=0; 
        for(int i=0;i<n;i++){
            if(i<n-2 && s[i]==s[i+1] && s[i+1]==s[i+2] && s[i]=='L') return false;
            if(s[i]=='A') {absent++; if(absent==2) return false;}
        }
    return true;
    }
};
