class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
       map<int, vector<int>>Pos;
        int n = nums.size() ; 
        
        for (int i=0; i<n; ++i){ 
            //Storing position of every element
            Pos[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n);
        
        for (auto it : Pos) {
            vector<int>curr = it.second;
            
            long long sum=0;
            
            for (auto x: curr)
                sum+=x-curr[0];
            
            ans[curr[0]]=sum;//putting first position value 
            

            //for rest
            for (int i=1; i<curr.size(); ++i) {
                
        // prefix will store the sum of absolute diff. from the starting index of current element to the current index.
                sum+=1ll*i*(curr[i]-curr[i-1]); 

        //  suffix will store the sum of absolute diff. from the ending index of current element to the current index.        
                sum-=1ll*(curr.size()-i)*(curr[i]-curr[i-1]);
                
                ans[curr[i]]=sum;
            }
        }
        
        return ans;
    }
};
