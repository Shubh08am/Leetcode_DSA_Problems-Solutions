class Solution {
public:
    /*bool isPowerOfThree(int n) {
        if (n<=0)
            return false;
        

        int r , sum=0 , temp = n;  
        
            while (temp>0)
            {
                r = temp%10 ;
                temp= temp/10;
                    sum=sum+r;
            }
            if (sum%3== 0)
                return true;
        
        return false;
        */
            
            bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        while(n!=1){
            if(n%3!=0){
                return false;
            }
            n=n/3;
        }
        return true;
    }
    
};
