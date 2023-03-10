class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>freq; 
        int mn = 1e9 ; 
        vector<string>ans;
        for(int i=0;i<list1.size();i++) freq[list1[i]]=i;
        for(int i=0;i<list2.size();i++) {
            if(freq.find(list2[i]) != freq.end()){
              freq[list2[i]]+=i+100000; 
        //      cout<< list2[i] << "\n" ;
              mn = min(mn , freq[list2[i]]) ; 
            }
         }
        for(auto it : freq){
            if(it.second==mn) ans.push_back(it.first) ;
        } 
        return ans;
    }
};
