#define ll long long
class Solution {
public:
    //find the cost required to convert each element of nums to mid
    ll costToEqual(vector<int>& nums, vector<int>& cost,ll mid){
        ll reqCost=0;
        ll n = nums.size();
        for(int i=0;i<n;i++){
            reqCost+=1ll*abs(nums[i]-mid)*cost[i];
        }
    return reqCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {

        //Search space :- Try to Form every value of nums equal in this range
        ll start=1 , end=*max_element(nums.begin(),nums.end()) ; 
        ll minCost=1e18;

        while(start<=end){

            //We will Try to convert each number of nums to mid
            ll mid = start+(end-start)/2;

            //Cost at mid 
            ll costMid = costToEqual(nums,cost,mid) ; 
            //Cost ahead mid
            ll costAheadMid = costToEqual(nums,cost,mid+1) ; 
            //Cost before mid
            ll costBeforeMid = costToEqual(nums,cost,mid-1) ; 

            //if the cost at mid is least than ahead or before it :- its the answer
            if(costMid<costAheadMid && costMid<costBeforeMid) return costMid;

            //Else move the search space to least cost 

            //if cost ahead mid is least move right 
            if(costMid>=costAheadMid && costMid<costBeforeMid) {
                //right move 
                minCost=min(minCost,costAheadMid);
                start=mid+1;
            }

            //if cost before mid is least move left 
            else if(costMid>=costBeforeMid && costMid<costAheadMid) {
                //left move
                 minCost=min(minCost,costAheadMid);
                 end=mid-1;
            }
        }
    return minCost;
    }
};
