class MyHashMap {
public:
    vector<int>dp;
    MyHashMap() {
        dp.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        dp[key]=value;
    }
    
    int get(int key) {
        return dp[key];
    }
    
    void remove(int key) {
        dp[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
