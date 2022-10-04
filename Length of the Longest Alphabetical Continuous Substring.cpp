class Solution {
public:
    int longestContinuousSubstring(string s) {
  vector<bool>visited(26,0); 
        
int ans = -1;
int cnt = 0;
for(int i=0;i<s.size();i++){
if(i!=0 and (s[i]-s[i-1] == 1)) {
if(visited[s[i]-'a']==0){	 
   // cout<< s[i] << endl;
	visited[s[i]-'a']=1;
	cnt++;	
}}
else { 
   // cout<< s[i] << " " << i << endl;
ans = max(ans,cnt);
for(int j=0;j<26;j++){
	 visited[j]=0;
} 
visited[s[i]-'a']=1;
cnt = 1;  
 //  i--; 
  //  cnt = 0;
}
} 
int res = max(cnt, ans);

return res;      
    }
};

Approach II:-
class Solution {
public:
    int longestContinuousSubstring(string s) {
        
int cnt =1;
int ans=0;
for(int i=0 ; i<s.size();i++){
if(i!=0 and s[i]-s[i-1] == 1) { 
cnt++;
	}	

else{	
	ans = max(ans,cnt);
	cnt = 1;				
}	
}

ans=max(ans,cnt);
return ans;
    }
};
