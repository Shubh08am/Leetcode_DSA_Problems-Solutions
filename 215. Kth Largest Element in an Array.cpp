class Solution {
public:
void heapify(vector<int>& nums , int i){
    int n=nums.size(); 
   int largest = i ; 
   int left = 2*i+1;
   int right = 2*i+2; 

   if(left<n && nums[largest]<nums[left]){
    largest=left;
   }
   if(right<n && nums[largest]<nums[right]){
    largest=right;
   }

   //swapping 
   if(largest!=i){
         swap(nums[largest],nums[i]);
         heapify(nums,largest);
   }
}

void heapsort(vector<int>& nums){
    int n=nums.size(); 
   //from non-leaf nodes 
   for(int i=n/2-1;i>=0;--i){
    heapify(nums,i);
   }
}
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size(); 
        heapsort(nums) ; //sorted in decreasing order max-heap
        for(auto&val : nums) cout<<val<<" "; 
         for(int i=1;i<k;i++){
            swap(nums[0],nums.back()) ; 
            nums.pop_back() ; 
            heapify(nums,0) ;
        }
        return nums[0];
    }
};
