class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
 map<int,int>ransom;
map<int,int>magzne;
bool flg = 0;
for(int i=0;i<ransomNote.size();i++){
int ch = ransomNote[i]-'a';
		ransom[ch]++;
}

for(int i=0;i<magazine.size();i++){
int ch = magazine[i]-'a';
		magzne[ch]++;
}

for(int i=0;i<ransomNote.size();i++){
int ch = ransomNote[i]-'a';
	if(ransom[ch]<=magzne[ch]){
		flg=1;
			}	
			
	else {flg=0;break;}
}

return flg;       
    }
};
