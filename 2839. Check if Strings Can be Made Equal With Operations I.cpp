class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=2;i<4;i++){
                if(s1[i] != s2[i]){
                    swap(s2[i],s2[i-2]);
                }
        }
        return s1==s2;
    }
};
