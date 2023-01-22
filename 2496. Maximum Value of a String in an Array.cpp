class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res=-1,ans=0;
        for(int i=0;i<strs.size();i++){
            string curr = strs[i];
            int cnt=0;
            for(int j=0;j<curr.size();j++){
                if(curr[j]>='0' and curr[j]<='9'){
                    cnt++;
                }
            }
            if(cnt==curr.size()){
                ans=stoi(curr);
            }
            else{
                ans=curr.size();
            }
            
            res=max(res,ans);
        }
        return res;
    }
};
