class Solution {
public:
    int minFlips(string target) {
        //Greedy Approach 
        //start from 0th index and go to last position and try to flip only when not same character(after flipped) 

        int flip=0,n=target.size();
        char currChar = '0' ;

        for(int i=0;i<n;i++){
            if(target[i]!=currChar){
                flip++;
                //Alter the curr char now as all flipped from [i---n-1] 
                currChar=target[i]; //as we flipped now,so all char from [i to n-1] becomes target[i]
            }
        }
        return flip;
    }
};
