class Solution {
public: 
static bool cmp(vector<int>&att , vector<int>&def){
	
if(att[0]==def[0]) return att[1]<def[1];
return att[0]>def[0];	
} 
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
 
int cnt = 0;
sort(properties.begin(),properties.end(),cmp);
int mn = -1 ; 

for(auto it : properties){
if(mn > it[1]) cnt++;
else mn = it[1];
  }
  
    
   return cnt;       
    }
};
