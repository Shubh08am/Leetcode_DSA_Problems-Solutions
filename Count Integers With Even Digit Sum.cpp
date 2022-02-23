class Solution {
public:
    int countEven(int num) {
// cnt variable keeps a record of total sum of digits which are even 

      int  cnt = 0  ;
// Now, using a for loop to iterate till the num
// We can also directly start i = 2 as it's the first even number 

        for ( int i = 1 ; i<= num ;i++)
        { 
// s keeps the sum of digits
// e keeps original i 

          int  e = i , s=0  ;
// Now, finding sum of digits using a while loop till (e > 0)    .
        
        while (e)
        {
// it gives last digits of a number
           int r = e %10 ; 
           s=s+r ; 
// It decreases the number so that we can find other digits as well
            e/=10;
        }
  // Now, if s is even it will be divisible by 2 and we will increment cnt  
     
            if( s%2 == 0 )          cnt ++;
        }
     return cnt ; 
    }
};
