class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        int n1  = mid-low+1 ; 
        int n2 = high-mid ;
        int left[n1] , right[n2]; 
        int k = low ; 
        for(int i=0;i<n1;i++){
            left[i]=nums[k++] ;
        }
        k=mid+1;
        for(int i=0;i<n2;i++){
            right[i]=nums[k++] ;
        }
        int ind1 = 0 , ind2 = 0 , s = low ; 
        while(ind1<n1 && ind2<n2){
            if(left[ind1]<right[ind2]){
                nums[s++]=left[ind1++];
            }
            else{
                nums[s++]=right[ind2++];
            }
        }
        while(ind1<n1){
             nums[s++]=left[ind1++];
        }
        while(ind2<n2){
            nums[s++]=right[ind2++];
        }
    }
    int countPair(vector<int>& nums,int low,int mid,int high){
        int cnt=0,right=mid+1; 
        //LEFT -> COMPARED WITH RIGHT PART BEFORE MERGING
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>1ll*2*nums[right]) {
              //  cout<< nums[i]<<" "<<nums[right]<<"\n";
                right++;
            }
            cnt+=(right-(mid+1));
        }
    return cnt;
    }
    int mergeSort(vector<int>& nums,int low,int high){
        int cnt = 0 ; 
        if(low>=high) return cnt ; 
        int mid = low + (high-low)/2; 
        cnt+=mergeSort(nums,low,mid) ; 
        cnt+=mergeSort(nums,mid+1,high) ;
        cnt+=countPair(nums,low,mid,high) ;
        merge(nums,low,mid,high) ; 
    return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
