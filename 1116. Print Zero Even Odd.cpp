class ZeroEvenOdd {
private:
    int n;
    int i;
    int turn ; 
    mutex m ; 
    condition_variable cv ; 

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i=1;
        this->turn=0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex>lock(m);

            //WAITING [LOCK] CONDITION 
            while(turn!=0 && i<=n){
                cv.wait(lock) ;
            }
            //EXIT CONDITION 
            if(i>n) break; 

            printNumber(0) ;
            turn=(i%2==0)?2:1; //IF i is EVEN turn=2 [print even no] else turn=1 [print odd no]
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex>lock(m);

            //WAITING [LOCK] CONDITION 
            while(turn!=2 && i<=n){
                cv.wait(lock) ;
            }
            //EXIT CONDITION 
            if(i>n) break; 

            printNumber(i++) ;
            turn=0;
            cv.notify_all();
        }
    }
    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex>lock(m);

            //WAITING [LOCK] CONDITION 
            while(turn!=1 && i<=n){
                cv.wait(lock) ;
            }
            //EXIT CONDITION 
            if(i>n) break; 

            printNumber(i++) ;
            turn=0;
            cv.notify_all();
        }
    }
};
