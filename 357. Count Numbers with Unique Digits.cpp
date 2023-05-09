/*
For n = 0, ans = 1
For n = 1, ans = 10
If we take 2 digit number, we have 9 options for first digit (1 - 9)
and 9 options for second digit(0 & all other digits except the one taken as first digit (to keep digits unique)) therefore ans += (9 * 9)
Similarly if we take 3 digit number we have 8 options for third digit, therefore ans += (9 * 9 * 8)
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)   return 1;
        int ans = 10, avail = 9, permutation = 9;
        for(int i = 0; i < n - 1; i++) {
            avail *= permutation;
            ans += avail;
            permutation--;
        }
        return ans;
    }
};
 
