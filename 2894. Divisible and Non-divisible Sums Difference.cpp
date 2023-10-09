class Solution {
public:
    int differenceOfSums(int n, int m) {
        long sum=0,sum2=0; 
        for(int i=1;i<=n;i++){
            sum+=(i%m==0?i:0);
            sum2+=(i%m==0?0:i);
        }
        return sum2-sum;
    }
};
