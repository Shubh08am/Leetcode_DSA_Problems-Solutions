class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n);
        vector<int> index(32,-1);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(v[i]&(1<<j)){
                    index[j]=i;
                }
            }
            int lasteleind=i;
            for(int j=0;j<32;j++){
                lasteleind=max(lasteleind,index[j]);
            }
            ans[i]=lasteleind-i+1;
        }
        return ans;
    }
};
