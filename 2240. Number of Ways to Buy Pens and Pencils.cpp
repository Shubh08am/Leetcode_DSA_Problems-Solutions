class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0; 
        int i=0;
        while(i<=total/cost1){
            int rem = total-cost1*i;
            ans+=rem/cost2+1;
            i++;
        }
        return ans; 
    }
};
