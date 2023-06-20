class Solution {
public:
    bool isPossible(vector<int>& nums,int mid , int maxOperations){
        int n = nums.size() ;
        //for telling no. of operation required inorder to 
        //reduce no. of balls in each bag to mid i.e no of ball 
        int requiredOperation = 0 ;

        for(int i=0;i<n;i++){
            int currOperation = nums[i]/mid ; 

            //If divisible 1 less operations required 
            // 8%4=0 -> 4 , 4 in 1 operation 
            if(nums[i]%mid==0){
                currOperation--;
            } 
        requiredOperation+=currOperation;
        }
    //Now,if we can divide no of balls in a bag to mid in given maxOperations
    //it is possible that mid is one of the answer 
    return requiredOperation<=maxOperations; 
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        // binary search on Search Space(answer)
        int n = nums.size() ; 

        //Search Space
        int start = 1 , end = *max_element(nums.begin(),nums.end()) ; 

        while(start<=end){
            //mid represent no. of balls in each bag at max 
            int mid = start + (end-start)/2 ; 

            //Check if it is possible to divide no. of balls (mid)
            //in a bag in given maxOperations  

            //If possible go left as we want to minimize answer 
            if(isPossible(nums,mid,maxOperations)){
                end=mid-1;
            }

            //If not Possible move right 
            else{
                start=mid+1;
            }
        }
    return start; 
    }
};
