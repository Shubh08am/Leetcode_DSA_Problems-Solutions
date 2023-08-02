class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        // left half -> 0 to n/2 
        // right half -> n/2 to n 
        int n = nums.size() ; 
        vector<int>Left,Right ; 

        //subset sum -> 2^n/2 
        for(int mask=0;mask<(1<<n/2);mask++){
            int sum=0;
            for(int i=0;i<(n/2);i++){
                if(mask&(1<<i)){
                    sum+=nums[i];
                }
            }
          //  cout<<sum<<" ";
            Left.push_back(sum);
        }

        for(int mask=0;mask<(1<<(n-n/2));mask++){
            int sum=0;
            for(int i=0;i<(n-n/2);i++){
                if(mask&(1<<i)){
                    sum+=nums[i+n/2];
                }
            }
          //  cout<<sum<<" ";
            Right.push_back(sum);
        }
      /*  for(auto it : Left) cout<<it<<" ";
        cout<<"\n";
        for(auto it : Right) cout<<it<<" ";
        */
        sort(Right.begin(),Right.end()) ; 

        int res = INT_MAX ; 

        for(int i=0;i<Left.size();i++){
            // Left_a + Right_b <= goal 
            // Right_b <= goal - Left_a 
            int Right_b = goal - Left[i] ; 
            auto it = lower_bound(Right.begin(),Right.end(),Right_b)-Right.begin() ; 

            if(it<Right.size()){
                res = min(res , abs(Left[i]  + Right[it] - goal) ) ;
            }
            if(it>0){
                res = min(res , abs(Left[i]  + Right[it-1] - goal) ) ;
            }
        }
    return res;
     }
};
