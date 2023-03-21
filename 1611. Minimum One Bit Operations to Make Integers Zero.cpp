class Solution {
public:
    int minimumOneBitOperations(int n) {
        // 6 = 6^3^1 --> (110^011^001) --> (100) --> 4 
        //3^1 --> (011^001) --> (010) --> 2
        int xorr = 0 ;
        while(n) {
            xorr=(xorr^n) ; 
            n>>=1;//divide by 2 
        }
        return xorr;
    }
};
