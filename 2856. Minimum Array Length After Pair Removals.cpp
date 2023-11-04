class Solution {
public:
    bool isPossible(vector<int>& nums,int mid){
        int n=nums.size(),left=0,right=n/2,cnt=0;
        while(right<n && left<n/2){
            if(nums[left]<nums[right]){
                left++;
                right++;
                cnt++;
            }
            else{
                right++;
            }
        }
  //  cout<<left<<" "<<right<<"\n";
    return cnt>=mid; //i.e mid numbers of pairs possible
    }   
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size() ;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        /*
        [2,3,4,4,4,5,5,6,7] -> max = 1
        [2,4] , [3,5] , [4,5] , [4,6] -> ans = 1
        
        [2,3,4,4,4,7,7,7,7] -> max = 4
        [2,7] , [3,7] , [4,7] , [4,7] -> ans = 1 
        
        [2,3,4,4,7,7,7,7,7] -> max = 5
        [2,7] , [3,7] , [4,7] , [4,7] -> ans = 1  
        
        min_pairs = 0 , max_pairs = n/2 
        binary search on pairs count 
        */
        int low=0,high=n/2; 
        while(low<=high){
            int mid = low+(high-low)/2; 
            if(isPossible(nums,mid)) low=mid+1;
            else high=mid-1;
        }
        int rem = n-2*high;
        return rem;
    }
};
