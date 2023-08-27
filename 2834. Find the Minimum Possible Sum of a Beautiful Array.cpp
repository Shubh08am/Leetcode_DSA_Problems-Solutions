class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0 , i=1; 
        set<int>s ; 
        while(s.size()<n){
            if(!s.count(target-i)){
                s.insert(i);
                ans+=i;
            }
            i++;
        }
    return ans;
    }
};
