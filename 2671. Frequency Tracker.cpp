class FrequencyTracker {
public:
    unordered_map<int,int>m;
    map<int,vector<int>>mp;
      FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp[m[number]].size()>0) mp[m[number]].pop_back();
        m[number]+=1;
        mp[m[number]].push_back(number);
     }
    
    void deleteOne(int number) { 
        
        if(m.find(number)!=m.end()){
            if(mp[m[number]].size()>0){
                 mp[m[number]].pop_back();
            }
            m[number]-=1;
              mp[m[number]].push_back(number);
            if(m[number]==0) m.erase(number);
        }
    }
    
    bool hasFrequency(int frequency) {
         return mp[frequency].size()>0;
    }
};
/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
