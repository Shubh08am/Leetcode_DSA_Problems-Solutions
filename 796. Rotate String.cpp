class Solution {
public:
    string make(string goal,int i){
        string s="";
        int m=goal.size() , pos=(i+1)%m;
        while(pos!=i){
            s+=goal[pos];
            pos=(pos+1)%m;
        }
        s+=goal[i];
    return s;
    }

    bool rotateString(string s, string goal) {
        int n=s.size() ,m=goal.size() ; 
        if(n!=m) return false; 

        for(int i=0;i<n;i++){
          //  cout<<make(s,i)<<" ";
            if(make(s,i)==goal)  return 1;
        }
    return 0;
    }
};
