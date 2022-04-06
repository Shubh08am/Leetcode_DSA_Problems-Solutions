class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        bool f=0;
        for(int i= 0 ; i<t.size();i++){
            if(s[i]!=t[i]) {return t[i]; f=1;}
        }
        if(f==0) 
            return t[t.size()-1];
        
        return 0;
    }
};
