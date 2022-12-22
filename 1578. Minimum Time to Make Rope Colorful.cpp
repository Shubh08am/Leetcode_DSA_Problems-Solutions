class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
int time = 0;
int n = colors.size();
int i=0,j=1;

while(j<n and i<n){
	
 if(colors[i]==colors[j]){
   int val = min(neededTime[i],neededTime[j]);  

if(val==neededTime[i]){
  // cout<<neededTime[i] << " "<<i << endl;
time+=neededTime[i];
i=j;
j++;          
     }  

else if(val==neededTime[j]){  
   //  cout<<neededTime[j] << " "<<j<< endl;
time+=neededTime[j];
j++;          
if(colors[i]!=colors[j]) {i=j; j++;}

     }     

 } 
 else{
     i++;
     j++;
 }
}

return time;        
    }
};
