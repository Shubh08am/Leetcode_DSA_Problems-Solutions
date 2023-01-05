class Solution {
public:
    long long int gcd(long long int a ,long long int b)
{
    /* base condition*/ 
    if(b==0) return a;
    return gcd (b,a%b );
}
 
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

    
     int subarrayLCM(vector<int>& nums, int k) {
        long long int cnt=0;
        long long int n = nums.size();
        
        for(int i=0;i<n;i++){
            long long int curr = nums[i]; 
            if(curr==k) cnt++;
            for(int j=i+1;j<n;j++){
                 long long int c = curr*nums[j]*1LL; 
                 long long int cc = __gcd(curr*1LL,nums[j]*1LL);
                long long int val = ((c)/(cc))*1LL;
                 if(val==k) {
                     cnt++;
                curr=val;
                 }
                else if(k%val!=0){
                    break;
                }
            }
        }
        return cnt;
    }
};
