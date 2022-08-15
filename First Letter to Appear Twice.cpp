class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>v(26,0);
        for(int i=0 ; i<s.size();i++){
     int ch = s[i] - 'a' ;
v[ch]+=1;
            if(v[ch] == 2){
                
                return 'a'+ch ;
                break;
            }
        }
        return -1;
    }
};
