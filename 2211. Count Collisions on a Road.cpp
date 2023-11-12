class Solution {
public:
    int countCollisions(string directions) {
        stack<char>s;
        int n=directions.size(),collisions=0;
        s.push(directions[0]);
        for(int i=1;i<n;i++){
            if(s.top()=='R' && directions[i]=='L'){
                collisions+=2;
                s.pop();
                s.push('S');
                s.push('S');
            }
            else if(s.top()=='R' && directions[i]=='S'){
                collisions++;
                s.pop();
                s.push('S');
                s.push('S');
            }
            else if(s.top()=='S' && directions[i]=='L'){
                collisions++;
                s.pop();
                s.push('S');
                s.push('S');
            }
            else s.push(directions[i]);
        }
        //some RS pair collisions still left

        //Leading RR Pairs removed as no collisions 
        while(!s.empty() && s.top()=='R'){
            s.pop();
        }
        //Left RS pairs
        while(!s.empty()){
            collisions+=s.top()=='R';
            s.pop();
        }
    return collisions;
    }
};
