class MyHashSet {
public:
    vector<int>dp;
    MyHashSet() {
        dp.resize(1000001,-1);
    }
    
    void add(int key) {
        dp[key]=key;
    }
    
    void remove(int key) {
        dp[key]=-1;
    }
    
    bool contains(int key) {
        return dp[key]!=-1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
