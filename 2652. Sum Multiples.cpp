class Solution {
public:
    int sumOfMultiples(int n) {
        long s=0;
        int i=1;
        while(i<=n){
            if(i%3==0 or i%5==0 or i%7==0) s+=i;
            i++;
        }
        return s;
    }
};
