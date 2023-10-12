/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length() ; 
        int low=0,high=n-1; 
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) low=mid+1;
            else high=mid-1;
        }
    return low;
    }
    int binarySearchAsc(int target,int peak,MountainArray &mountainArr) {
        int n = mountainArr.length() ; 
        int low=0,high=peak; 
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(mountainArr.get(mid)==target) return mid;
            if(mountainArr.get(mid)<target) low=mid+1;
            else high=mid-1;
        }
    return -1;
    }
    int binarySearchDesc(int target,int peak,MountainArray &mountainArr) {
        int n = mountainArr.length() ; 
        int low=peak,high=n-1; 
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(mountainArr.get(mid)==target) return mid;
            if(mountainArr.get(mid)>target) low=mid+1;
            else high=mid-1;
        }
    return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length() ; 
        // 2 times binary search from 0-peak+index (Ascending order) 
        // than from peak+1 to n-1 (Descending order) 
        int peak = peakIndexInMountainArray(mountainArr);
        int pos = binarySearchAsc(target,peak,mountainArr) ;
        if(pos!=-1) return pos; 
        pos = binarySearchDesc(target,peak+1,mountainArr) ;
        return pos;
    }
};
