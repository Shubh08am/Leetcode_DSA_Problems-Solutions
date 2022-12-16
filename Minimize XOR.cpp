class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int res=0;
        int m= __builtin_popcount(num2);
        int n= __builtin_popcount(num1);
        
        for(int i=0;i<=31;i++){
            int k=1<<i;
            int r= num1 & k;
            if(r==0 && m>n){
                res = (res|k);
                m--;
            }
            else if(r && n>m) n--;
            else res= res|r;
        }
        return res;
    }
};
