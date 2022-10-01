class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0 ;
        int ind1 = 0 ; 
        int ind2 = 0 ;
        
        map<char,int>mp,m;
        for(auto i :s1) mp[i]++;
                for(auto i :s2) m[i]++;

        for(int i=0;i<s1.size();i++){ 
        if(s1[i]!=s2[i] and m[s1[i]]>0 and mp[s2[i]]>0) { cnt++; if(cnt==1) {ind1 = i;} if(cnt==2) {ind2 = i;}  }
            
            else if(m[s1[i]]==0 || mp[s2[i]]==0) {
                return  false;
            }
            
        }
        swap(s2[ind1],s2[ind2]);
        return (s1==s2);
    }
};
