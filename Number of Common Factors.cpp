class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt=0; 
        int x = max(a,b) ;
        for(int i=1;i<=x;i++){
            if(a%i==0 and b%i==0) cnt++;
        }
        return cnt;
    }
};
