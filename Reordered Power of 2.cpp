class Solution {
public:
    bool reorderedPowerOf2(int n) {
   vector<int>ds(30,0);
for(int i=0;i<30;i++){
int pwr = pow(2,i);	
ds[i]= pwr;	
}

// n converted to string and sorted
string convert = to_string(n);
sort(convert.begin(),convert.end());

	
for(int i=0;i<30;i++){ 
    //2's power also converted to string and sorted --> done
    string pwr_2 = to_string(ds[i]); 
    sort(pwr_2.begin(),pwr_2.end());
if(convert == pwr_2) {
	return true;
}
}

return false;     
    }
};
