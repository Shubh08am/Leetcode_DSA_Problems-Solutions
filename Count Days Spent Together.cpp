class Solution {
public:
    
int days(string&s){
	
int year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int month1 = (s[0]-'0')*10;	
int month2 = (s[1]-'0') ;	

int month = month1 + month2 ;	

int day1 = (s[3]-'0')*10;	
int day2 = (s[4]-'0') ;	

int day = day1 + day2 ;		

//cout<< month << endl;		
for(int i=0; i<month-1 ;i++){ 
day+=year[i];			
}
 
//cout<< day<< endl;
return day;			
} 
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
 int ans=0;
int alicearr = days(arriveAlice) ;
int bobarr = days(arriveBob);
int alicelev = days(leaveAlice);
int boblev = days(leaveBob);

int intersection1 = max(alicearr , bobarr);
int intersection2 = min(alicelev , boblev);

if(intersection1  > intersection2) {	
ans = 0;	
}

else{	
ans = intersection2 - intersection1 + 1 ;	
}

return ans;
       
    }
};
