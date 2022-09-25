class Solution {
public:
    bool checkPowersOfThree(int n) {
vector<int>ds ; // storing power of 3's in ds
int start_index = -1;
int sum=0; // this keeps track of sum i.e powers of 3 
        
//iterating till 16 only keeping constraints in mind
for(int i=0;i<16;i++){ 
int pwr = pow(3,i);
ds.push_back(pwr);
}
        
// now, finding just smaller position of n in ds 
        // ex: 91 --> goes till 91>81 , but 243>91
for(int i=0;i<16;i++){
if(ds[i]<n){
	continue;
	}
	else {
        // update start index here with 243 index i.e 5
        start_index=i; 
    }	
	
}

// decrement start index here as we start with 81 (index i.e 4) as sum value 
 start_index--;
 
        
//now,iterating from back i.e reverse loop 
 while( start_index>=0){
//everytime update sum value and check if it is smaller or greater than n
 	sum+=ds[start_index];
     
     // if sum is smaller than or equal to n -->continue
 if(sum<=n){
 	
 }
 
     //else if not :- than remove the last inserted value from sum 
 	else{
    sum-=ds[start_index];
 	}	
 		start_index--;
 }
// at last if sum is same as n return true else return false
        
return sum==n;
    }
};
