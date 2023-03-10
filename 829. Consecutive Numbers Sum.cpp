class Solution {
public:
    int consecutiveNumbersSum(int n) { 
        //a + a + 1 + a + 2 ... + a + k = (k+1)a + (1+2+...+k)= (k+1)a + (k*(k+1)/2) = N 
        // a = N/(k+1) - k/2 
        //a>0 -> N>K*(K+1)/2;
        int ans = 0;
        for(int k=0;k*(k+1)/2<n;k++){
            //valid k exist  // a = N/(k+1) - k/2 
            double dummy = (n*1.0)/(k+1) - k/2.0 ; 
        //    cout<<dummy<<" "; 
            if(dummy==floor(dummy)) ans++;
        }
        return ans;
    }
};
