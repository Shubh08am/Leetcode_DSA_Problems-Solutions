class Solution {
public:
    int binarySearch(vector<int>& arr){
        int n=arr.size();
        int start=0,end=n-1;

        while(start<end){
            int mid = start+(end-start)/2;

            if(arr[mid]>arr[mid+1]){
                end=mid;
            }
            else if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
        }
        return start;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return binarySearch(arr) ; 
    }
};
