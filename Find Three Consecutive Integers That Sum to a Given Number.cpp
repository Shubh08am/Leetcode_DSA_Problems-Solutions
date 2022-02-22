class Solution {
public:
    vector<long long> sumOfThree(long long num) {
       vector<int> a;
        
     
        if(num%3==0)
        {  
              long long int x = (num-3)/3;
            return {x,x+1,x+2} ;
        }
    
            return{} ;
   
    }
};
