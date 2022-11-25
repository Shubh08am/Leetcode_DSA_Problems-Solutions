class MyCircularQueue {
public:
    
     vector<int> ans;
    int i = 0, j= 0, size, mx = 0;
    
    MyCircularQueue(int k) {
        ans.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        ++mx;
        ans[j] = value;
        ++j;
        if(j== size)
            j= 0;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        --mx;        
        i++;
        if(i == size)
            i = 0;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return ans[i];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return ans[(j-1+size)%size];
    }
    
    bool isEmpty() {
        if(mx == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(mx == size)
            return true;
        return false;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
