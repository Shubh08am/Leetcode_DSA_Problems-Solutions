class KthLargest {
public:
    multiset<int>ms;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto it : nums) ms.insert(it);
    }
    
    int add(int val) {
        ms.insert(val);
        int cnt=0; 
        for(auto it=ms.end();it!=ms.begin();cnt++,it--){
           if(cnt>=k) return *it;
        }
        return *(ms.begin()) ; //when only 1 element 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
