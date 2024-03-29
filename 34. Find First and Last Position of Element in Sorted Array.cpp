// function for finding the first occurence of an element
int firstOccurence(vector<int>&nums , int target)
{
    int s=0;  // starting position
    int e = nums.size()-1;   // ending position
    int mid = s+(e-s)/2;    // middle position
    int res = -1;  // stores result
    
    while(s<=e)
    {
        if(nums[mid]==target)
        { res = mid; 
            e = mid-1;  // checking left part again if we get first occurence less than the current one
        }
       else if (nums[mid]>target)
       {
           e = mid-1;
       }
        
        else 
            s=mid+1;
        
        mid = s+(e-s)/2;  // updating middle position
    }
    return res;
    }
    
  // function for finding the last occurence of an element  
 int lastOccurence(vector<int>&nums , int target)
{
    int s=0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;
    int res = -1;
    
    while(s<=e)
    {
        if(nums[mid]==target)
        { res = mid;
            s = mid+1;// checking right part again if we get last occurence more than the current one
        }
       else if (nums[mid]>target)
       {
           e = mid-1;
       }
        
        else 
            s=mid+1;
        
        mid = s+(e-s)/2;
        }
    return res;
    }


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     
        // Creating a vector of size 2 and initiallizing all elements with -1
        
        vector<int>ans(2,-1); 
        // if no elements than return -1
       if(nums.size()==0)
           return ans; 
       
        // else update the vector by calling the function crearted
       ans[0]=firstOccurence(nums, target);
       ans[1]=lastOccurence(nums, target);
        
        
       return ans; 
    }
};
