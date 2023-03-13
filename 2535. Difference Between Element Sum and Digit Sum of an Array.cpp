class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
    return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum2=0,sum=0;
         for(auto&it : nums){
            sum2+=digitSum(it);
            sum+=it;
        }
        return abs(sum-sum2 );
    }
};
