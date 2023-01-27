class Solution {
public:
     
int countDigitOne(int n) {
        long long int count_of_ones = 0;
for (long long int i = 1; i <= n; i *= 10) {
            int prefix = (n/(i*10));
            int digit = (n/i)%10; 
            int suffix = n%i;

            if (digit == 0) {
                count_of_ones += prefix*i;
            } 
            else if (digit == 1) {
                count_of_ones += prefix*i + suffix + 1;
            } 
            else {
                count_of_ones += (prefix + 1)*i;
            }
        }
        return count_of_ones;
    }
};
