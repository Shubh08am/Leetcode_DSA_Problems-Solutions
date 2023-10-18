class Solution {
public:
    map<int,set<string>>m;
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size() , mn = 1e9; 
        for(int i=0;i<n;i++){
            int one=0;
            for(int j=i;j<n;j++){
                one+=(s[j]=='1') ;
                if(one>=k) {m[j-i+1].insert(s.substr(i,j-i+1)) ; mn=min(mn,j-i+1) ; }
            }
        }
        return mn==1e9?"":*(m[mn].begin()) ;
    }
};
