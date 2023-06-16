class Solution {
public:
    string smallestString(string s) {
        int n = s.size() ,i=0; 
        string p = "" ;
        
        while(s[i]=='a' && i<n) i++;
        if(i==n){
            s[i-1]='z';
            return s;
        }
        
        for(int k=i;k<n && s[k]!='a';k++){
            //if(s[k]!='a') 
                s[k]--;
        }
        
        return s ;
    }
};
