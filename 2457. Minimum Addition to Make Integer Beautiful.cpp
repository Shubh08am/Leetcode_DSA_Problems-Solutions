class Solution {
public: 
    
    long long int find(long long int n){
    	long long int sum =0;
    	while (n){
    	sum += n%10;
    	 	n/=10;}
    	 	return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
            
 /*
 1447 , 1--> 1450 --> 1500 --> 2000 --> 10000  
 res = 10000-1457 = 8553
 47,2 ---> 50 --> 100   
 i.e change every pos from back one by one 
   */      
        
        long long int res =0;
        while (find(n) > target ){
            long long int val = 1;
            long long int curr= n ;
            while (curr&&curr%10==0){
            	curr/=10;
            	val*=10;
            }
                       
            val*= (10-curr%10);
            res += val;
            n += val;
        }
        return res;    
    }
};
