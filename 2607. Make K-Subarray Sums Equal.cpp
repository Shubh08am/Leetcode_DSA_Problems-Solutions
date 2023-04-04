class Solution {
public:
    long long int cnt(vector<int> &arr){
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int median = arr[n/2];
        long long int ans = 0;
        for(auto i : arr) ans+= abs(median - i);
        return ans;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        k = __gcd(n,k); 
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<n;i++) mp[i%k].push_back(arr[i]);
        long long int ans = 0;
        for(auto i : mp) ans += cnt(i.second);
        return ans;
    }
};
