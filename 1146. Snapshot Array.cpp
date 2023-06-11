class SnapshotArray {
public:
    map<int,map<int,int>>snaps;
    int snapId = 0 ;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++){
            map<int,int>curr;
            curr[0]=0;
            snaps[i]=curr;
        }
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val ;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        //APPLY BINARY SEARCH NOW 
        auto it = snaps[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
