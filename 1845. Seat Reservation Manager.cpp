class SeatManager {
public:
    multiset<int>ms;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) ms.insert(i);
    }
    
    int reserve() {
        int seatNo = *(ms.begin()) ;
        ms.erase(seatNo);
        return seatNo ;
    }
    
    void unreserve(int seatNumber) {
        ms.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
