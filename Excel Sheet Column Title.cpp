class Solution {
public:
    string convertToTitle(int n) {
          string res;
        
        while (n>0){
            if (n%26==0){
                res = 'Z' + res;
                n = n/26 -1;
            }else{
                res = char(n%26 -1 + 'A') + res;
                n = n/26;
            }
        }
        return res;
    }
};
