class Solution {
public:
    bool leapYear(int year){
        if(year%400==0) return 1 ; 
        if(year%100==0) return 0 ; 
        if(year%4==0) return 1 ; 
        return 0;
    }
    int dayOfYear(string date) {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;

        int d = (date[8]-'0') * 10 + (date[9] -'0') ;
        int m = (date[5]-'0') * 10 + (date[6] -'0') ;
        int y =  (date[0]-'0') * 1000 + (date[1] -'0')*100 + (date[2]-'0') *10 + (date[3] -'0') ;
        int mm = accumulate(days,days+m,0);
        return d+mm+((leapYear(y) && m>2)?1:0);
    }
};
