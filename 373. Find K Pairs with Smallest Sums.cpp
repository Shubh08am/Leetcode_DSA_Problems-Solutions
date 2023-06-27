class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
    vector<vector<int>> ans;
    priority_queue<pair<int, pair<int, int>>> pq; // max-heap to store the k smallest pairs
    int n = nums1.size() , m = nums2.size() ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            int currSum = nums1[i] + nums2[j];

            if (pq.size() < k) {
                pq.push({currSum, {nums1[i], nums2[j]}});
            }
            else if (currSum < pq.top().first) {
                pq.pop();
                pq.push({currSum, {nums1[i], nums2[j]}});
            } 
            else if (currSum > pq.top().first) {
            //    cout<<i<<" "<<j<<"\n";
                break;
            }
        }
    }
   // cout<<pq.size();
    while (!pq.empty()) {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    return ans;
    }
};
