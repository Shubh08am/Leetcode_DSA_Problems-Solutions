class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
       
             if(n==1)
            return 1;
        
        int a=0 , b=1 , temp;
        for(int i=1; i<n ; i++)
        {
            temp = a;
            a = b;
            b = b+ temp;
        }
        return b;
    }
};
