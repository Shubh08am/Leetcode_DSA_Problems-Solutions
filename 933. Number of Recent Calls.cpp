class RecentCounter {
public:
    vector<int>v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        return v.size()-(lower_bound(v.begin(),v.end(),t-3000)-v.begin()) ;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
