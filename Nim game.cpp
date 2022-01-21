class Solution {

public:

    bool canWinNim(int n) {

     

    /*  while ( n>0 ) 

      {

          int a = n-1;

          int b = n-2;

          int c = n-3; 

          

          if ( a== 0 || b==0 || c== 0)

              return true;

      }*/

        return n%4 ;

    }

};
