class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char,int>m,mp ; 
        for(auto&it:brokenLetters) m[it]++;
        int cnt=0; int ans=0;
        mp=m;
        for(int i=0;i<text.size();i++){
            if(text[i]!=' '){
                if(m[text[i]]) {
                    cnt++;
                }
            }
                else{
                    m=mp ; 
                    if(cnt==0) ans++;
                    cnt=0;
                }
        }
        if(cnt==0) ans++;
        return ans ;
    }
};
