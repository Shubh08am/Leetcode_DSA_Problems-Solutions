class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    /* Think -> Greedy + heap -> to keep track of curr highest freq 
    first Highest Freq one --for n times use Second High Third so on or IDLE--- Again first Highest freq -- so on -> 
    when first Highest Freq = 0 -> shift to Second Highest Freq
    keep track when the task will be avaiable again -> curr_time + n after this -> use some data structure for it 
    */  

    priority_queue<int>pq; 
    unordered_map<char,int>freq; 
    for(auto&t:tasks) freq[t]++;
    int ans = 0 ;
    for(auto&occurence : freq){
         pq.push(occurence.second);
     }

     while(!pq.empty()){
        vector<int>taskRemains ; 
        int LastCycleTime = 0 ; 

        //one cycle runs for -> n
        for(int i=0;i<n+1;i++){
            if(!pq.empty()){ 
                //task done therefore reduced by 1 
                taskRemains.push_back(pq.top()-1) ; 
                pq.pop() ; 
                LastCycleTime++;
            }
        }

            //one cycle completed -> put back in pq now remaining tasks to be done 
            for(auto&it:taskRemains) {
                //if task still left i.e > 0 
                if(it>0) pq.push(it) ; 
            }
        //everytime n+1 time taken in each cycle except last  cycle where only some tasks 
        // are left there it depends on left tasks determined by time 
        //ex:- tasks = ["A","A","A","B","B","B"], n = 2 
        // A B IDLE -> ONE CYCLE = n+1 , A -> 2 , B-> 2
        //A B IDLE -> ONE CYCLE = n+1  , A -> 1 , B->1
        // A B -> 2 and not n+1 -> = 2 -> pq empty stop -> last step 
        ans+= pq.empty()?LastCycleTime:n+1;
     }
     return ans;
    }
};
