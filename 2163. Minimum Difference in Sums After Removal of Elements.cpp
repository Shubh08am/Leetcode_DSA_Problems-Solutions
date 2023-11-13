class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        //first half -> min sum 
        //second half -> max sum 
        //diff minimized 
        priority_queue<long>maxHeap;
        priority_queue<long,vector<long>,greater<long>>minHeap; 
        int n=nums.size();  
        vector<long long>left_min(n,LONG_MAX),right_max(n,LONG_MAX);
        long long curr_sum=0,ans=1e18;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            maxHeap.push(nums[i]);
            if(maxHeap.size()>n/3){
                curr_sum-=maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size()==n/3)left_min[i]=curr_sum;
        }
        curr_sum=0;
        for(int i=n-1;i>=0;i--){
            curr_sum+=nums[i];
            minHeap.push(nums[i]);
            if(minHeap.size()>n/3){
                curr_sum-=minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size()==n/3)right_max[i]=curr_sum;
        }
        /*
        for(auto it : left_min) cout<<it<<" ";
        cout<<"\n";
        for(auto it : right_max) cout<<it<<" ";
        cout<<"\n";
        */
        for(int i=0;i<right_max.size()-1;i++){
         if(left_min[i]!=LONG_MAX && right_max[i+1]!=LONG_MAX)   ans=min(ans,1ll*(left_min[i]-right_max[i+1]));
        }
    return ans;
    }
};
