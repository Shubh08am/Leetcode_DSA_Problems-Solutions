class Solution {
public:
    int minSteps(string s, string t) {
    int ans = 0;
    map<char,int>m,mp;

    for(auto&it:s) m[it]++;
    for(auto&it:t) mp[it]++;

    for(auto&it:s){
    	if(mp[it]>0){
        		mp[it]--;
                	}
                    else ans++;
                    }

                    for(auto&it:t){
                    	if(m[it]>0){
                        		m[it]--;
                                	}
                                    else ans++;
                                    }

                                    return ans;    
    }
};
