class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

vector<string>words;
int n = queries.size();
int m = dictionary.size();
map<string,int>nonRepeated;
        
for(int i=0;i<n;i++){
	//search each queries[i] in dictionary
	string quer_curr = queries[i];
	
	for(int j=0;j<m;j++){
		int different_pos = 0;	
		string dic_curr = dictionary[j];
      //  cout<<dic_curr<<" ";
		int size_dic_curr = dic_curr.size();
		
	 for(int k=0;k<size_dic_curr;k++){
		//differ in max 2 pos
		if(quer_curr[k] != dic_curr[k]){
			different_pos++;
		}
	}
	
	if(different_pos <=2){
		if(!nonRepeated[quer_curr]){
			words.push_back(quer_curr);
	}
		nonRepeated[quer_curr]++;
       // continue;
	}
	//cout<<"\n";
	} 
    nonRepeated.clear();
}

return words;        
    }
};
