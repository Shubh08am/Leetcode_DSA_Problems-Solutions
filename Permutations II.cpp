class Solution { 
     private: 
    void find_permutation(vector<int>&nums,vector<int>&freq,vector<vector<int>>&ans,vector<int>&ds){
	
//base case
if(ds.size()== nums.size()){ 
ans.push_back(ds);
	return;
} 

//recursion case
for(int i=0; i<nums.size();i++){

	//if not present in freq
	if(!freq[i]){
		ds.push_back(nums[i]);
		//than mark it in freq so next time we won't include it
		freq[i]=1;
		
		//Recursion call now 
		find_permutation(nums,freq,ans,ds);
		
		//now backtracking time - remove from freq and ds 
		freq[i]=0;
		ds.pop_back();			
				}	
	
	
}


    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans , er;
vector<int>ds;
vector<int>freq(nums.size(),0);
find_permutation(nums,freq,ans,ds);

/* 
set<vector<int>>s;
        
for(vector<int>it:ans){
  cout<<it[0]<< " ";
s.insert(it.begin(),it.end());
    }
   
 for(vector<int>it : s){ cout<<it[0]<<" ";} */ 
 
/* set<vector<vector<int>>>s;
        	
s.insert(ans.begin(),ans.end());

    vector<vector<int>>res;
    
 for(vector<int> it : s){res.push_back(it);}
 
	for(vector<int>it:res){
		for(auto itt:it){
			cout<<itt<<" ";
		}cout<<endl;
	}*/ 
   sort(ans.begin(),ans.end());
for(int i=0;i<ans.size()-1;i++){
  if(ans[i]!=ans[i+1]) { er.push_back(ans[i]);   
} }
    er.push_back(ans[ans.size()-1]); 
  /*  vector<vector<int>>res;
    
 
	for(vector<int>it:ans){
		for(int itt:it){ 
		cout<<itt<< " ";
res.push_back({itt});

		}cout<<endl;
    }   
     */   
    return er;
    }
};
