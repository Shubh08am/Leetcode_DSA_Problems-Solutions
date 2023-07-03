class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int notsame = 0 , n = s.size() , m = goal.size() , f=0 , g=0; 
        int len = min(n,m);
        if(n!=m || n==1 || m==1) return false;
        char ch1 , ch2 ;
        for(int i=0;i<len;i++){
            if((s[i]!=goal[i] && notsame==0)|| (s[i]!=goal[i] && goal[i]== ch1 && s[i]==ch2 )) {
                notsame++;
                ch1 = s[i] ; 
                ch2 = goal[i] ;
                }
             else if(s[i]!=goal[i]) return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]==s[0]) f++;
        }
        for(int i=0;i<m;i++){
            if(goal[i]==goal[0]) g++;
        }
        if(f==n&&g==m)return true;
        if(s==goal){
            //any character occur twice true 
            for(char ch='a';ch<='z';ch++){
                int c=0;
                for(int i=0;i<n;i++) {
                    if(s[i]==ch) c++;
                }
                if(c>1) return true;
            }
        return false;
        }
        return notsame==2;
    }
};
