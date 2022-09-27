class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
  int n=s.size();
map<int,int>mp;
string ss ; 
        

    
for(int i=0;i<n;i++){
	if(mp[s[i]]!=0){
mp[s[i]]=i-mp[s[i]];	
	}
else mp[s[i]]=i;	
}

set<char>st;
for(int i=0;i<n;i++){
st.insert(s[i]);
		}
		
for(auto i:st){
ss+=i;	
		}
		 
        
for(int i=0;i<ss.size();i++){ 
   // cout << mp[s[i]]-1 << " " << distance[i] << endl;
if(mp[ss[i]]-1 != distance[ss[i] - 'a']) {
	return false;
		}	
}


return true;      
    }
};
