class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = 1+minutesToTest/minutesToDie;
        int cnt=0;
        while(pow(rounds,cnt) < buckets){
            cnt++;
        }
    return cnt;
    }
};
