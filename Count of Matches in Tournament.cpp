class Solution {
public:
    int numberOfMatches(int n) {
         int m , ans=0;
        while(n>1){
            m = (n+1)/2 ; 
            if(n&1) ans+=m-1;
            else ans+=m;
             n=m;
        }
        return ans;       
    }
};
