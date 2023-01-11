class RandomizedSet {
public:
    vector<int>ans;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (mp.find(val) == mp.end()){
        ans.push_back(val);
        mp[val] = ans.size() - 1;
        return true;
        } 
        return false;
    }
    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
int pos = ans.back();
        mp[pos] = mp[val];
        ans[mp[val]] = pos;
        ans.pop_back();
        mp.erase(val);
        return true;
        }
        return false;
        
    }
    int getRandom() {
        int random = rand() % ans.size();
        return ans[random];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
