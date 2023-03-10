class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //bfs,dfs works
        // 1,12,123,..
        //2,23,234...
        //3,34,345...
        //so on till 9 

        queue<int>q; 
        for(int i=1;i<10;i++) {
            q.push(i);
        }
        vector<int>digit;
        while(!q.empty()){
            int number = q.front();
            q.pop() ; 
        // initially number = 1 -> make it 12 than 123 so on 
           int lastDigit = number%10 ; 
           int  newNo = number*10+lastDigit+1  ; // 12 = 1*10 + 1+1 || 123 = 12*10 + 12+1

           //if front element of queue in limit take it in answer 
         if(number>=low && number<=high)  digit.push_back(number);

         //when lastDigit 9 don't do further operation 
        if(lastDigit==9) continue;
        
        if(newNo<=high) q.push(newNo);

        }
        return digit;
    }
};
