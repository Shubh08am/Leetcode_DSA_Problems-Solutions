class Solution {
public:
    int strStr(string haystack, string needle) {

int n = needle.size(); 
int m = haystack.size();

//we will iterate till this size as after this size it's not possible to search 
int search_space = m-n+1;

//using substring and finding dummy_ans of size n and if it is equal to needle we return its index as we found our answer else if not found return -1

for(int i=0;i<search_space;i++){
	string dummy_ans = haystack.substr(i,n);
	if(dummy_ans == needle){
	return i;	
			}				
}
return -1;        
    }
};
