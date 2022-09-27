class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
   int n = nums.size();
int i=0;
int j=n-1;
long long int sum = accumulate(nums.begin(),nums.end(),0LL);
long long int sum_i=0;
long long int sum_j = sum;
long long int ans = INT_MAX;
long long int diff = 0;
long long int index = INT_MAX;
vector<long long int>store;
while(i<n-1){
	
sum_i+=nums[i]; 
sum_j-=nums[i]; 

int first = (sum_i)/(i+1);
int second ; 
    if((n-i-1)!=0){ second = (sum_j)/(n-i-1);}

diff = abs(first - second); 
 
    store.push_back(diff);
   
i++;	
} 
   store.push_back(sum/n);   
        for (int i=0 ; i<store.size();i++) { 
            if(store[i]<index) {index = store[i]; ans=i;}
        }
return ans;     
    }
};
