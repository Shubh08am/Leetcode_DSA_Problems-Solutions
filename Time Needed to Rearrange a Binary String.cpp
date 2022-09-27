class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0;
bool check = 0;


while(true){ 
    bool flg = false;
for(int i=0;i<s.size()-1;i++){	

    
	if(s[i]=='0' && s[i+1]=='1'){ 
        swap(s[i],s[i+1]); 
        i++;
	flg=true;	
	}
}
	if(flg) cnt++;
	else break;

}
return cnt;
    }
};
