class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,end=1,n=gas.size();
        int fuel = gas[0]-cost[0];
        while(start!=end || fuel<0){
            while(start!=end && fuel<0){
                fuel-=gas[start]-cost[start];
                start=(start+1)%n;
                if(start==0) return -1;
            }
            if(end<n)fuel+=gas[end]-cost[end];
            end=(end+1)%n;
        }
    return start;
    }
};
