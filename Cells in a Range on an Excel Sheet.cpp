class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char a = s[0], b = s[3], x = s[1], y = s[4];
        for (; a <= b; ++a) {
            for (char i = x; i <= y; ++i) {
                ans.push_back(string(1, a) + string(1, i));
            }
        }
        return ans;
    }
};
