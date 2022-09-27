class Solution {
public:
    int partitionString(string s) {
      set<char>st; int ans=0;
        
        for(auto i:s){
            if(st.find(i)!=st.end()){
                ans++;
                st.clear();
                st.insert(i);
            }
            else st.insert(i);
        }
        ans++;
        return ans;
    }
};
