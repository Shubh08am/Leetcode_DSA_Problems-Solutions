class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int>ds ;
int start_index = -1;
int sum=0;
for(int i=0;i<16;i++){
int pwr = pow(3,i);
ds.push_back(pwr);
}
for(int i=0;i<16;i++){
if(ds[i]<n){
	continue;
	}
	else { start_index=i; }	
	
}

 start_index--;
 
 while( start_index>=0){
 	sum+=ds[start_index];
 if(sum<=n){
 	//sum+=ds[ start_index];
 }
 
 	else{
    sum-=ds[start_index];
 		//start_index--;
 			}	
 		start_index--;
 }
//cout<<sum<<endl;
return sum==n;
    }
};
