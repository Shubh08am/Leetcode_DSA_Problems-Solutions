class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        //Monotonicity found 
        //USE PREV_SMALLER AND NEXT_SMALLER LOGIC 
        // PREV_SMALLER BEFORE K AND NEXT_SMALLER AFTER K 
        // ith ELEMENT CONTRIBUTION -> (NEXT_SMALLER[i]-PREV_SMALLER[i]-1)*nums[i] 
        stack<int>s; 
        int n=nums.size(),score=0;
        vector<int>prev_smaller(n) , next_smaller(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
            if(s.empty()) prev_smaller[i]=-1;
            else prev_smaller[i]=s.top();
            s.push(i);
        }
        s={}; //this clears the stack 
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
            if(s.empty()) next_smaller[i]=n;
            else next_smaller[i]=s.top();  
            s.push(i);

        }
        /*for(auto&it:prev_smaller) cout<<it<<" ";
        cout<<"\n";
        for(auto&it:next_smaller) cout<<it<<" ";
        cout<<"\n";
        */
        for(int i=0;i<n;i++){
            if(prev_smaller[i]<k && next_smaller[i]>k){
                int contribution = (next_smaller[i]-prev_smaller[i]-1)*nums[i];
                score=max(score,contribution);
            }
        }
    return score;
    }
};
