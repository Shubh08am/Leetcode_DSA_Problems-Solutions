class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int>freq;
        for(auto&it : num) freq[it-'0']++;
        for(int i=0;i<num.size();i++){
        if(freq[i]!=(num[i]-'0')) return false;
        }
        return true;
    }
};
