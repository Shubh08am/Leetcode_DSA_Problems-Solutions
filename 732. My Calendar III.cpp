class MyCalendarThree {
public:
map<int,int>calender;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
      calender[start]++;
      calender[end]--;


   int booking = 0 , session=0;

   for(auto&it:calender){
       session+=it.second;
       booking=max(booking,session);
   }

        return booking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
