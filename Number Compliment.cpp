class Solution {

public:

    int findComplement(int num) {

        

        int ans = 0 ;

        // it keeps a track on final answer.

        int i = 0;

        // keeps track on bits

while ( num )

{

    if ( (num&1) == 0 )

     ans +=1<<i ;

    

    /* i.e if the bit is 0 we will set it to 1 else no need to set.*/

    i+= 1 ;

    num >>=1 ;

    //num = num >> 1 ;

}

        return ans;

    } 

    

};
