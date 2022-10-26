class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int ans = 0;
int cnt = 1 ;
int n=prices.size();
for(int i=1 ; i<n;i++){
	int val = prices[i-1]-prices[i];
	if(val == 1){
	cnt++;	
	}
else{	

	ans+= 1LL *(cnt+1)*(cnt*1LL)/2;
	cnt=1;	
}	
}

ans+= 1LL *(cnt+1)*(cnt*1LL)/2;
return ans;
    }
};
