class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        for(auto it : operations){ 
             if(it=="C") ans.pop_back();
            else if(it=="D") ans.push_back(ans.back()*2);
            else if(it=="+") ans.push_back(ans[ans.size()-2]+ans.back()); 
            else ans.push_back(stoi(it)) ;
        }
        long long int sum = accumulate(ans.begin(),ans.end(),0LL);
        return sum;
    }
};
