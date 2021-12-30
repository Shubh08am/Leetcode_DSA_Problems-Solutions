class Solution {
public:
    int mySqrt(int x) {
        
  
//float a = pow(x, 0.5);
        //1st method

        int a = sqrt(x);
     
return a;
    }
};

        // 2nd method using binary search-
 /*       
         int left = 1 ;
        int right = x;
while(left<right)
{ 
        int mid = (left +right)/2;
        int temp = x/mid;
       
if (temp==mid)
    return mid;

      else  if (mid > temp) 
            right = mid - 1;
        
else //if (mid < temp )
left = mid-1 ;
}
            return(left -1 );
    }
};*/
