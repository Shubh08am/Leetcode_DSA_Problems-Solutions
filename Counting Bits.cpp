class Solution {
public: 
int countSetBits(int n){
     int set = 0;
     while(n){
 	 set+=(n&1);
 	 n>>=1;
    }
 return  set;	
    }
    vector<int> countBits(int n) {
vector<int>bits(n+1,0);
for(int i=1;i<=n;i++){ 
    int x = i&1;
 //   cout<< x << " " << (i&1) << "\n";
	//bits[i]=countSetBits(i);//O(nlogn) 
    bits[i]=bits[(i>>1)] + x ; //O(n)
}
return bits;
    }
};
