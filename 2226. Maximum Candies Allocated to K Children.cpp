class Solution {
public:
    bool isPossible(vector<int>& candies, long long k,int mid){
        long long noOfCandies = 0 ; 
        for(auto&candy:candies){
            noOfCandies+=candy/mid;
        }
    //if it is possible to distribute no. of candies (mid)
    //to k Children , it is possible that mid is one of the answer 
    return noOfCandies>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // binary search on Search Space(answer)

        //Search Space
        int start = 1 , end = *max_element(candies.begin(),candies.end()) ; 
        int maxCandy = 0 ; 

        while(start<=end){
            //mid represent no. of candies  
            int mid = start + (end-start)/2 ; 

            //Check if it is possible to distribute no. of candies (mid)
            //to k Children

            //If possible go right as we want to maximize answer 
            if(isPossible(candies,k,mid)){
                maxCandy=mid;
                start=mid+1;
            }

            //If not Possible move left 
            else{
                end=mid-1;
            }
        }
    return maxCandy; // return end ; 
    }
};
