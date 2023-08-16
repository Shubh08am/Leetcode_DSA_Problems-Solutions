class Solution {
public:
    string solve(int n){
        if(n==1) return "1" ; 

        string curr = solve(n-1) ; 
        //cout<<n<<" "<<curr<<"\n";
        string res = "" ; 
        for(int i=0;i<curr.size();i++){
            char ch = curr[i] ; 
            int occur = 1 ; 
            //count occurence -> like one two three .. 
            while(i+1<curr.size()&&curr[i]==curr[i+1]){
                i++;
                occur++;
            }
            //change to string now -> ex:- 1 -> one 1 -> 1 1
            res+=to_string(occur)+ch;
            //cout<<n<<" "<<res<<"\n";
        }
    return res;
    }
    string countAndSay(int n) {
        return solve(n) ; 
    }
};
