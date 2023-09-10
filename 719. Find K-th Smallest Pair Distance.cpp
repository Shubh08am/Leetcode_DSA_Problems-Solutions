class Solution {
public:
    //finding number of pairs with difference <= mid 
    bool isPossible(vector<int>& nums,int mid, int k) {
        int pairs = 0 , i = 0 , j = 0 , n = nums.size() ; 
        while(j<n){
            while(nums[j] - nums[i] > mid) i++;
            pairs+= j-i;
            j++;
        }
   // cout<<pairs << " " << mid << "\n" ; 
    return pairs >= k ;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // binary search + sliding windows + bs on difference technique of aggressive cows 

        sort(nums.begin() , nums.end()) ; 
        int n = nums.size(), low = 0 , high = nums[n-1]-nums[0] ; 

        while(low<=high){
            int mid = low + (high-low) / 2 ; 
        //    cout<<low<<" "<<high<<" "<<" "<<mid<<"\n";
            if(isPossible(nums,mid,k)) high = mid-1;
            else low = mid+1; 
        }
    return low;
    }
};
