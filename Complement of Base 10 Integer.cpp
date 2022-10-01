class Solution {

public:

    int bitwiseComplement(int n) {

        if ( n==0)

            return 1 ;

        int ans = 0 , two=1 ;

        

     while (n)

     {

    int bit = n&1 ;

         if ( bit==0)

             ans+=two;

       two<<=1 ;

         n>>=1 ;

     }

        return ans;

         

        

    }

};
        
