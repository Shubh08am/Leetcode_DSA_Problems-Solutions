class Solution {
    bool good(int x, vector<int> &w, int days) {
        int s = 0, cnt = 1;
        for(int i : w) {
            if(i > x) return false;
            s += i;
            if(s > x) {
                cnt++;
                s = i;
                if(cnt > days) return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0, e = 1e8, ans = INT_MAX;
        while(s <= e) {
            int m = (s + e) /2;
            if(good(m, weights, days)) ans = min(ans, m), e = m - 1;
            else s = m + 1;
        }
        return ans;
    }
};
