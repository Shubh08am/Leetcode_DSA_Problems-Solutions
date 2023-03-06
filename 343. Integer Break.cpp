class Solution {
public:
    int integerBreak(int n) {
        //8 - 18(3 3 2)
        //9 - 27(3 3 3)
        //15 - 243(3 3 3 3 3)  
        //16 - 324 (3 3 3 3 4)
        //17-  486 (3 3 3 3 3 2)
        //18 - 486 (3 3 3 3 3 3)
        int ans=1;
        if(n==2) return 1; // 1(1 1) 
        if(n==3) return 2 ;  // 2(2 1) 
        if(n==4) return 4 ; // 4(2 2)
        //use 3 till n >4 
        while(1){
               if(n<=4){ 
                   ans*=n; 
                   return ans;
                   }
                else{
                    ans*=3;
                    n-=3;
                }

        }
        return 1;
    }
};
