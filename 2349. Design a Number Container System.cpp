class NumberContainers {
public:
     map<int,multiset<int>>pos;
     map<int,int>lastPos;
    NumberContainers() {
        
    }
    
    void change(int index, int number) { 
        if(lastPos[index]!=0){
            //some index already at that number, erase them 
            //ex:- (1,10) earlier now (1,20) -> update at 20 -> 1
            pos[lastPos[index]].erase(index);
        }
        //update latest position and insert
         lastPos[index] = number ;
         pos[number].insert(index); 
    }
    
    int find(int number) { 
        if(pos[number].empty()) pos.erase(number); // if 0 return that is it is empty return -1;
        if(pos.find(number)==pos.end()) return -1; 
        int ans = *(pos[number].begin());
         return ans; 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
