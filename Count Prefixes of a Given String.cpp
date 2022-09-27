class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
     int cnt = 0 ; 
        for(int i=0;i<s.size();i++){
	
	string a = s.substr(0,i+1); 
           // cout<< a << endl;
 cnt += count(words.begin(),words.end(),a);
	
}
return cnt; 
    }
};
