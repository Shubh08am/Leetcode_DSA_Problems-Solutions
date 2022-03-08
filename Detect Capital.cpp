class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cnt=0 , c=0 , cc=0 , ccc=0;
        for(int i=0;i<word.size();i++){
            if(  word[i] >= 97 && word[i] <=122)  cnt++;
            
            else if(  word[i] >= 65 && word[i] <=90)  c++;
        }
        for(int i=1;i<word.size();i++){
                         if(  ( word[i]  >= 97 && word[i] <=122 ) )  cc++;
            
        }
        
        if(word[0] >= 65 && word[0] <=90)  ccc++;
            
        if(c == word.size())  return 1;
        else if(cnt == word.size())  return 1;
        else if(cc+ccc == word.size())  return 1;
        else 
            return 0;
    }
};
