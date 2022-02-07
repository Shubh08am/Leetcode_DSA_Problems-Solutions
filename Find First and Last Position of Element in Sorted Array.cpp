int first(vector<int>&nums , int target)
{
    int s=0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;
    int f = -1;
    
    while(s<=e)
    {
        if(nums[mid]==target)
        { f = mid;
            e = mid-1;}
       else if (nums[mid]>target)
       {
           e = mid-1;
       }
        
        else 
            s=mid+1;
        
        mid = s+(e-s)/2;
    }
    return f;
    }
    
    
 int last(vector<int>&nums , int target)
{
    int s=0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;
    int l = -1;
    
    while(s<=e)
    {
        if(nums[mid]==target)
        { l = mid;
            s = mid+1;}
       else if (nums[mid]>target)
       {
           e = mid-1;
       }
        
        else 
            s=mid+1;
        
        mid = s+(e-s)/2;
        }
    return l;
    }


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         
        vector<int>res(2,-1);
        int n=nums.size();
       if(n==0)
           return res; 
        
       int f= first(nums, target);
       int l= last(nums, target);
       res[0]=f;
       res[1]=l;
       return res; 
    }
};
