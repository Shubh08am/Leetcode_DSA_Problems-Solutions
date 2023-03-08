class Solution {
public:
    int maxValue(vector<int>& piles){
        int mx = piles[0] ; 
        for(auto &val : piles) mx=max(mx,val);
        return mx;
    }
    int eatTime(vector<int>& piles , int mid){
        int time = 0 ; 
        for(auto &val:piles){
              time+=(val+mid-1)/mid ;//without ceil
          //   time+=ceil(val*1.0/mid); //using ceil 
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search on answer 
        //As search space can be reduced and we need to minimized result 
        //No,need to sort piles as we can apply binary search on answer (from mid directly) 
        
        //Take start to be 1 and end to be Max element of piles 
        int start = 1 , end=maxValue(piles); 
        int k = 0 ; 
        //when start==end that means we got our answer
          while(start<end){
            int mid = start + (end-start)/2; 
            //Now,check In how much time koko can eat bananas per hour using mid hours 
            k = eatTime(piles,mid) ; 
        //   cout<<k<<" "<<mid<<"\n";

         //Move, Left and update end to mid
            if(k<=h){
            end=mid;
            }
        //Move, Right and update start to mid+1
            else if(k>h){
            start=mid+1;
            }
        } 
        return start;
    }
};
