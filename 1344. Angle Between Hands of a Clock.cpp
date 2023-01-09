class Solution {
public:
    double angleClock(int hour, int minutes) {
 double hr = hour + minutes*1.0/60.0;
         if(hr>=12) hr-=12;

                                   double min = 1.0*minutes/5.0;

                                                 double res= abs(hr-min)*30;
                                                         if(res>180) res=360-res;
                                                                 return res;       
    }
};
