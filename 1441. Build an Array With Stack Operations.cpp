class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        string push = "Push" , pop="Pop" ; 
        int at=1;
        for(auto&val:target){
            while(at<val){
                ans.push_back(push);
                ans.push_back(pop);
                at++;
            }
            ans.push_back(push);
            at++;
        }
     return ans;
    }
};
