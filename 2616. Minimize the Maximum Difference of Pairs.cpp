#define ll long long
class Solution {
public:
    bool ok(vector<int>& nums, int p,ll mid,int n){
       ll pairFormed=0;
        
        for(int i=0;i<n-1;i++){
            ll diff = nums[i+1]-nums[i];
            if(diff<=mid){
                pairFormed++;
                i++; //as take one index only once therefore skip i+1th as pair formed between i&i+1th element
            }
        }
        //see if we formed required p pairs atleast
     return pairFormed>=p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
         sort(nums.begin(),nums.end());
         ll n = nums.size(),res=0;
         ll s=0 , e=nums[n-1]-nums[0]; //max differnce will be between last and first element 
      
        while(s<=e){
            ll mid = s + (e-s)/2 ; //indicates difference to check for forming pairs
            
            if(!ok(nums,p,mid,n)){
                //Not possible to form p pairs in left half as well as difference there wil be <mid therfore go to right half
                s=mid+1;
            }
            else if(ok(nums,p,mid,n)){
                res = mid; //  possible to form p pairs in right half as well as difference there wil be >=mid therefore go to left half 
                e = mid-1;
            }
        }
        return res; 
        
    }
};
