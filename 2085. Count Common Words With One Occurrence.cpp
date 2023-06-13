class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int>mp,pm;
        int n = words1.size() , m = words2.size() , cnt=0; 

        for(int i=0;i<n;i++){
            if(mp.find(words1[i])!=mp.end()){
                mp[words1[i]]=-1;
            }
            else{
                mp[words1[i]]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(pm.find(words2[i])!=pm.end()){
                pm[words2[i]]=-1;
            }
            else{
                pm[words2[i]]=1;
            }
        }
        for(int i=0;i<m;i++){
            cnt+=mp[words2[i]]==1 && pm[words2[i]]==1;
        }
    return cnt;
    }
};
