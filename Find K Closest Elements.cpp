class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
 /*int left = 0 , right = 0 , index = -1 , ind = 0;
vector<int>ans;

int mn = arr[0];
int mx = arr[arr.size()-1];

for(int i=0;i<arr.size();i++){
	if(arr[i]<=x){  index = i;}		
}

for(int i=0;i<arr.size();i++){
	if(arr[i]>x){  ind = i; break;}		
} 
        
if(mn>x){	
	//take from start
	for(int i=0;i<k;i++) {
	ans.push_back(arr[i]);	
	}
}
 

else if(mx<x){

	//take from end	
	for(int i=arr.size()-1;i>=0;i--) {
if(k>0) {
		ans.push_back(arr[i]);
		k-=1;
			}	
	}		
}


else{
	
//two pointer -> see left and right side from just smaller position	
    if(x-arr[index]<=arr[ind]-x){
	ans.push_back(arr[index]);
	left = index-1; 
    right = index+1;
    } 
    
    else { 
      ans.push_back(arr[ind]);  
      left = ind-1; 
     right= ind +1 ;
    }
while( ans.size()!=k and left>=0 and right<=arr.size()-1){
if( x-arr[left] < arr[right]-x){
ans.push_back(arr[left]);
left--;	
}

else if( x-arr[left] >arr[right]-x){
ans.push_back(arr[right]);
right++;	
}	

else if( x-arr[left] == arr[right]-x){
	
	if(arr[right] < arr[left]){
ans.push_back(arr[right]);
right++;
}

else if( arr[left] < arr[right]){
ans.push_back(arr[left]);
left--;	
}
		
}						
}	
} 
sort(ans.begin(),ans.end());        
return ans;    */    
        int n = arr.size();
            vector<int> ans;
            if(x < arr[0]){
                for(int i=0;i<k;i++) ans.push_back(arr[i]);
            }
            else if(x > arr[n-1]){
                for(int i=n-1;i>=n-k;i--) ans.push_back(arr[i]);
            }
            else{
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                int i= idx-1, j=idx;
                while(i>=0 and j<n and ans.size() < k){
                    int d1 = abs(arr[i]-x);
                    int d2 = abs(arr[j] - x);
                    if(d1 <= d2){
                        ans.push_back(arr[i]);
                        i--;
                    }
                    else if(d1 > d2){
                        ans.push_back(arr[j]);
                        j++;
                    }
                }
                while(i>=0 and ans.size() < k){
                    ans.push_back(arr[i]);
                    i--;
                }
                while(j<n and ans.size() < k){
                    ans.push_back(arr[j]);
                    j++;
                }
                
            }
            sort(ans.begin(), ans.end());
            return ans;
    }
};
