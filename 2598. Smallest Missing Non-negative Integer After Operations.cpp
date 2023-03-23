#define ll long long 
const ll mod = 1e9 ;
class Solution {
public: 
 ll m(vector<int>& nums, ll n, ll value){ 
    unordered_map<ll, ll> m;

    for (int i = 0; i < n; i++) {
        m[(nums[i] +  mod) % value]++;
    }

    for (int i = 0; i < n; i++) {
        ll op = (i+mod) % value ;
        if (m.find(op) == m.end()) {
            return i;
        }
        m[op]--;
        if (m[op] == 0)
            m.erase(op);
    }
    return n;
}
    int findSmallestInteger(vector<int>& nums, int value) {
      ll n = nums.size();
      return m(nums,n,value);
 
    }
};
