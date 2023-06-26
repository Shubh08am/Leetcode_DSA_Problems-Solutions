class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> minHeap1,minHeap2;
        long long ans=0;
        int workers = 0,i=0,j=costs.size()-1;

        while(workers<k){
            while(i<=j && minHeap1.size()<candidates) {
                minHeap1.push(costs[i]);
                i++;
            }
            while(j>=i && minHeap2.size()<candidates) {
                minHeap2.push(costs[j]);
                j--;
            }

            int fromLeft=minHeap1.empty()?INT_MAX:minHeap1.top();
            int fromRight=minHeap2.empty()?INT_MAX:minHeap2.top();

           //when equal take from left smaller index one 
            if(fromLeft<=fromRight){
                ans+=fromLeft;
                minHeap1.pop();
            }
            else if(fromLeft>fromRight){
                ans+=fromRight;
                minHeap2.pop();
            }
        workers++;
        }
    return ans;
    }
};
