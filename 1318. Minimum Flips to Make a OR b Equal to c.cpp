class Solution {
public:
    int minFlips(int a, int b, int c) {
       //check all 32 bits if a or b any bit set and corresponding c bit not set flip it and vice versa 
        long long flip=0,ax=1,bx=1,cx=1;

       for(int i=0;i<32;i++){
           ax=(1<<i) ;
           bx=(1<<i) ; 
           cx=(1<<i) ; 
           int set = (c&cx) ; 

           if(set){
                //either a or b should be set 
                if((a&ax) || (b&bx)) continue; 
                //if both not set than set any one 
                flip++;
           }
           else{
               //if c bit not set both a and b bit should be unset 
               //both a and b bit unset 
               if((a&ax) && (b&bx))  flip+=2; 
               // a bit set and b bit unset 
               if((a&ax) && !(b&bx))  flip++;  
                // a bit unset and b bit set 
               if( !(a&ax) && (b&bx))  flip++; 
           }   
         }
       return flip;
    }
};
