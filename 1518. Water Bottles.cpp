class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
     /*  int ans = numBottles;
        while(numBottles/numExchange >=1 ) {
            numBottles = numBottles - numExchange + 1;
            ans++;
        }
        return ans;
        */

        int ans = numBottles  + (numBottles-1)/(numExchange-1); 
          return ans;
    }
};
