class Semaphores{
    private:
    mutex mtx;
    int count;
    condition_variable cv;
    public:
    Semaphores() {}
    Semaphores(int c) {
        count=c;
    }
    void setcount(int num){
        count=num;
    }

     void wait(){
        unique_lock<mutex>lock(mtx) ; 
        count--;
        while(count<0){
            cv.wait(lock);
        }
    }

     void signal(){
        unique_lock<mutex>lock(mtx) ; 
        count++;
        if(count<=0){
            cv.notify_all();
        }
    }
};

//SOLUTION :- PICK BOTH LEFT AND RIGHT FORK TOGETHER [IN ONE CRITICAL SECTION] & RELEASE TOGETHER
class DiningPhilosophers {
public:
    Semaphores fork[5] ; 
    mutex m;

    DiningPhilosophers() {
        for(int i=0;i<5;i++){
            fork[i].setcount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        {
                        lock_guard<mutex>lock(m);
                        fork[(philosopher+1)%5].wait();
                        fork[philosopher].wait();
                        
                        }
                    pickLeftFork();
                    pickRightFork();

                    eat();

                    putLeftFork();
                    fork[(philosopher+1)%5].signal(); 
                    putRightFork();
                    fork[philosopher].signal();
    }
};
