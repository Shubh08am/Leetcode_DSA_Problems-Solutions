class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>a,v=arr;
        sort(v.begin(),v.end()) ; 
        map<int,int>mp; 
        int pos=1;
        for(auto i : v){
            if(mp.find(i)==mp.end()){
                mp[i]=pos++;
            }
        }
        for(auto i : arr) a.push_back(mp[i]) ; 
    return a;
    }
};
