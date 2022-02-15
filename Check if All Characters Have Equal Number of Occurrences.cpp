class Solution {

public:

    bool areOccurrencesEqual(string s) {

        unordered_map<char,int>m ;

        for(int i=0;i<s.size();i++){

            m[s[i]]++;

        }

        unordered_set<int>st;

        for(auto i: m){

            st.insert(i.second);

        }

        if(st.size()==1){

            return 1;

        }

        return 0;

    }

};
