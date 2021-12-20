class Solution {
public:
    bool isPalindrome(int n) {
        
           if(n < 0 || (n % 10 == 0 && n != 0)) {
            return false;
        }
        
        int digit, rev = 0;
   
  while (n > rev)
{
     digit = n % 10;
     rev = (rev * 10) + digit;
      n = n / 10;
      
     } 
    return  n==rev || n == rev/10 ;

    }
};
