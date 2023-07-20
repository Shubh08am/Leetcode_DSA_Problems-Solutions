class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n = asteroids.size() ; 
        s.push(asteroids[0]) ;
        for(int i=1;i<n;i++){
            //RR
              if(!s.empty() && s.top()>=0 && asteroids[i]>=0) s.push(asteroids[i]) ; 
            //LL
             else if(!s.empty() && s.top()<0 && asteroids[i]<0) s.push(asteroids[i]) ; 
              //LR
             else  if(!s.empty() && s.top()<0  && asteroids[i]>0) s.push(asteroids[i]);
             else{
                //RL WITH  UN-EQUAL
                while(!s.empty() && s.top() > 0 && s.top()<abs(asteroids[i])) s.pop();
                //RL WITH EQUAL
               if(!s.empty() && s.top()==abs(asteroids[i])) s.pop();
                else if(s.empty() || s.top()<0) s.push(asteroids[i]);
             }
        }
        int i = s.size()-1;
        vector<int>asteroid(i+1);
    while(!s.empty()){
        asteroid[i--]=s.top() ;
        s.pop();
    }
    return asteroid;
    }
};
