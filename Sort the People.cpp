class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>vp;
        vector<string>ans(names.size());
        
        for(int i=0;i<names.size();i++){
            vp.push_back({heights[i],names[i]});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());

        for(int i=0;i<vp.size();i++){
           // cout<<vp[i].first<<endl;
    ans[i]=vp[i].second;
}
        return ans;
    }
};
