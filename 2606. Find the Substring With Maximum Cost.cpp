class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26);
        for(int i=0;i<26;i++)
            cost[i]=i+1;
        
        int k=chars.size();
        for(int i=0;i<k;i++)
            cost[chars[i]-'a']=vals[i];
        
        long long ans=0;
        long long curr=0;
        for(auto ele : s)
        {
            curr=curr+cost[ele-'a'];
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        return ans;
    }
};
