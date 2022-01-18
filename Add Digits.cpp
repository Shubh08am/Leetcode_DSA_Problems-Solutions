class Solution {

public:

    int addDigits(int num) {

        

      /*

      if(num == 0)

            return 0;

        

        if(num % 9 == 0)

            return 9;

        

        else

            return num % 9;

            */

       int sum = 0 , r=0; 

        

        while ( num >=10 )

        { 

             while ( num>0)

             { 

                 r = num%10;

                 sum+=r;

                 num/=10;

             }

            num = sum ;

           sum = 0 ;

        }

        return num ;

    }

};
