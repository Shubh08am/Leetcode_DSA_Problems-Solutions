class Solution {

public:

    bool isHappy(int num) {

       

        int sum = 0 , r=0 ,m; 

    

        if ( num == 1 || num == 7 || num == 10 || num== 1111111)

            return true ; 

        

        while ( num>=10)

{ 

           /* if ( num = 1111111)

                return true ;*/

             while (num)

             { 

                 r = num%10;

                m = pow ( r ,2);

                sum+=m;

                 num/=10;

             }

            num = sum ;

           sum = 0 ;

        }

         return (num == 1) ;

           /*  return true ;

        

        else

return false;*/

    }

};
