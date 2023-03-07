class Solution {
public:
	//count totalTrips for the given time
    long long int numberOfTrips(vector<int>&time ,long long int givenTime){
        long long int totalTrips = 0;
        for(auto it : time){
            long long int curr = it;
            totalTrips += (givenTime / curr);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>&time,int totalTrips) {
        long long int start = 1;
        long long int end = 1e14;
        while(start<end)  {
            long long int mid = start + (end-start)/2;
            
            //move left to check whether less time taken to complete totalTrips
            if(numberOfTrips(time , mid) >= totalTrips){ 
                end = mid;
            }
            //move right to complete totalTrips
            else if(numberOfTrips(time , mid) < totalTrips){
                start = mid+1;
            }
        }
        return start;
    }
};
