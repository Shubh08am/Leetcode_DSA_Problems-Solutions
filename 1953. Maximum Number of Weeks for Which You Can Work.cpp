class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
         long long int sum=0 , sum2=0, ans=0;
        //greedy 
        //if max element sum > all element except max than ans is 2*all element except max + 1 
        for(auto&it : milestones) {
            sum2 = max((int)sum2,it) ;
            sum+=it;
        }
        sum-=sum2; //all element except max
        if(sum2>sum)  ans=2*sum+1;
        //if not whole sum of milestones answer
        else ans = sum+sum2;

        return ans;
    }
};
