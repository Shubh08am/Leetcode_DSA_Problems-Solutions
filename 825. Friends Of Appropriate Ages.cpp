class Solution {
public:
    int upperBound(int key,vector<int>&ages){
        int n = ages.size() ,low=0,high=n-1,ans=0; 
        while(low<=high){
            int mid = low+(high-low)/2; 
            if(ages[mid]<=key) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        if(ages[n-1]<= key) return n ; 
        return ans; 
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end()) ; 
        // x = 18  , y = 16 -> no request 
        int n = ages.size(),ans=0;
        for(int i=0;i<n;i++){
            int age_x = ages[i] ; 
            int age_y = ages[i] / 2 + 7 ; 
            int a = upperBound(age_x,ages) ; 
            int b = upperBound(age_y,ages) ; 
            //cout<<age_x<<" "<<age_y<<" "<<a<<" "<<b<<"\n";
            ans+=max(a-b-1,0) ; 
        }
    return ans;
    }
};
