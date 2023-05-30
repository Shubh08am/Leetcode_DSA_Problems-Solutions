class Skiplist {
public:
    vector<int>dp;
    Skiplist() {
        dp.resize(200001,0);
    }
    
    bool search(int target) {
        return dp[target]>0;
    }
    
    void add(int num) {
        dp[num]++;
    }
    
    bool erase(int num) { 
       return dp[num]>0?--dp[num],true:false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
