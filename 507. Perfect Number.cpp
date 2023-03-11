class Solution {
public: 
    int divisorSum(int num){
        long long int sum = 0 ; 
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                if(num/i!=i){
                    sum+=(num/i)+i;
                }
                else {
                    sum+=i;
                }
            }
        }
        return sum;
    }
    bool checkPerfectNumber(int num) {
        long long int sum = divisorSum(num) - num ; 
        return sum==num ;
    }
};
