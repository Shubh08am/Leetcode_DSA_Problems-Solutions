class Solution {
public:
    int tribonacci(int n) {
       /* if(n==0) return 0 ;
        else if(n==1||n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);*/
   if(n <= 1) return n;     
        int prev3 = 0, prev2 = 1, prev1 = 1;
        
        for(int i = 3; i <= n; i++)
        {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
