class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> ms(changed.begin(), changed.end());
        vector<int> ret;
        while (!ms.empty()) {
            int a = *ms.begin();
            ms.erase(ms.begin());
            ret.push_back(a);
            auto it = ms.find(2 * a);
            if (it == ms.end()) return {};
            ms.erase(it);
        }
        return ret;
    }
};
