class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      
int n=nums.size(),split=0; 
vector<long long>pre(n,0),suf(n,0);
for(int i=0;i<n;i++){
	pre[i]=nums[i];
	suf[i]=nums[i];
}
for(int i=1;i<n;i++){
	pre[i]+=pre[i-1];
}
for(int i=n-2;i>=0;i--){
	suf[i]+=suf[i+1];
}
for(int i=0;i<n-1;i++){
    split+=suf[i+1]<=pre[i];	
}
return split;   
    }
};
