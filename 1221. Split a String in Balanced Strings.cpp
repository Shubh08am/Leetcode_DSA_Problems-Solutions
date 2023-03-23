class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0,l=0,cnt=0,n=s.size(),i=0,ok=0;
        while(i<n){
            r+=s[i]=='R',l+=s[i]=='L';
            ok=(l==r)?1:0 ; 
            if(ok) cnt++,l=r=0;   
            i++;
        }
    return cnt;
    }
};
