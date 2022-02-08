
class Solution {
public:
    int mySqrt(int n) {
          
          int left = 0 ;
          int right = n;
         long long int mid = left +  (right-left)/2;
       
        long long int ans=-1;
        
while(left<=right)
{  long long int temp = mid*mid;
       
if (temp==n)
    return mid;

      if ( temp > n) 
      right = mid - 1;
        
else if (n > temp )
{  ans = mid;
left = mid+1 ; 
}
    
  mid = left +  (right-left)/2;  
}
            return ans;
    }
};
