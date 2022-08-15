class Solution {
public:
   static bool cmp(vector<int>&v, vector<int>&vv){
	return v[1]>vv[1] ;	
   }  
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      int size = boxTypes.size();
sort(boxTypes.begin(),boxTypes.end(),cmp);

int sum = 0;


for(int i = 0 ; i<size ; i++){

// when taking all no.of  boxes
if(truckSize-boxTypes[i][0] >=0){

	sum+= ( boxTypes[i][1]*boxTypes[i][0] ) ;		
	truckSize-=boxTypes[i][0];
}

// for left case like boxno -> 5 but we take 1 that cases after this break
else {
	sum+=(truckSize*boxTypes[i][1]);
	break;
}

}
return sum;  
    }
};
