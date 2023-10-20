#define ll long long
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size() , cnt=0; 
        ll ans = 0 ;
        unordered_map<int,int>factorWant;
        /*  t.c -> o(n*sqrt(k))
Time: For each number, we go over all divisors of k. A tight bound on the number of divisors can be had, but sqrt(k) is a good upper bound (since divisors occur in pairs). So time complexity is O(n * sqrt(k)). This could be considered amortized cost as the amortized O(1) cost of unordered_map access is should also be in there.
        */
        for(int i=0;i<n;i++){
            int g = __gcd(nums[i],k);
            int wantNo = k/g ; 
            for(auto & [number,occurence] : factorWant){
                ans+=(number%wantNo==0)?occurence:0;
            }
            factorWant[g]++;
        }
    return ans;
    }
};
