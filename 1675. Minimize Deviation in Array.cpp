class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      set<int>deviation;
        for(auto it:nums){
            if(it & 1) deviation.insert((it<<1));
            else deviation.insert(it);
        }
        int maxi = *deviation.rbegin(); 
        int mini = *deviation.begin();  
        int ans = INT_MAX;

        while(!(*deviation.rbegin()&1)){
            int currMax = *deviation.rbegin();
            deviation.erase(currMax);
            deviation.insert(currMax/2);
            ans = min(ans,*deviation.rbegin()-*deviation.begin());
        }
        return ans;     
    }
};
