class Solution {
public:
    bool isSameAfterReversals(int num) {
        int wer =0 , rev = 0 ; 
        int s = 0 ; 
        int w = num ; 
        
        while(num)
        {
            
            
           int r = num%10 ; 
            rev = r  + 10* rev ;
            num/=10;
        }
        
        while(rev) 
        { 
            
        int e = rev%10;
            wer = e + 10 * wer ; 
            rev/=10;
            
            
            
        }
return wer == w ;
    }
};
