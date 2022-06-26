class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
// int n = words.size();
vector<string>v;

for(int i=1 ; i<words.size() ; i++){
    
	string s = words[i];
	string ss = words[i-1]; 

		sort(s.begin(),s.end());
             sort(ss.begin(),ss.end());
                  if(s==ss)
	{ 
	
        words.erase(words.begin() + i);
                      i--;
	} 

}
return words;       
    }
};
