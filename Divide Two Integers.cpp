class Solution {
public:
    signed long long int divide(long long int dividend, long long int divisor) {
       
        if( dividend == -2147483648 && divisor== -1)
            return 2147483647 ;
       
        else
        {signed int m = dividend/divisor;    
        return m;}
        
    }
};
