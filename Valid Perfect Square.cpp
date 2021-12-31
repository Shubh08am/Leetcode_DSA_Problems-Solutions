class Solution {
public:
    bool isPerfectSquare(int num) {
        int Left = 0 ;
        long long right = num;
        bool ans = false ;
        while(Left<=right)
        {
           long long mid = (Left + right)/2;
            
            long long x = mid * mid;
            if( x > num)
            {
                right = mid-1;
            }
            else if(x< num)
            {
                Left = mid+1;
            }
            else 
            {
               ans = true;
                break;
            }

        }
        return ans ; 
    }
};
