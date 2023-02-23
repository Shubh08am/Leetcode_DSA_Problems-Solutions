class Solution {
public:
    // for same capital, we give more priority to the
    // project with higher profit
    static bool compare(pair<int,int>& a, pair<int,int>& b) {
        if(a.first == b.first) return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> arr;

        for(int i=0; i<n; ++i) {
            arr.push_back(make_pair(capital[i],profits[i]));
        }
        sort(begin(arr), end(arr), compare);

        int idx = 0;
        priority_queue<int> pq;

        // while we are left with some projects
        while(k>0 and idx<n) {
            // we insert profits of all the projects with capital <= w
            // into the priority queue
            while(idx<n && arr[idx].first <= w) {
                pq.push(arr[idx].second);
                ++idx;
            }
            // if profit<=0 then simply skip
            while(!pq.empty() and pq.top() <= 0) {
                pq.pop();
            }
            // if we don't have any project with capital <= w, then we
            // can't do any more project as arr is sorted on the
            // basis of capital
            if(pq.empty() and idx<n and arr[idx].first > w) break;
            // else do the current project with maximum profit
            --k;
            w += pq.top();
            pq.pop();
        }
        // All the projects present in pq are having capital <= w
        // So, if we can still complete some projects
        while(k>0 and !pq.empty() and pq.top() > 0) {
            --k;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
