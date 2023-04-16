class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {   
        if(income==0) return 0.0;
        
        double ans=0;
        int prev=0; 
        
        for(int i=0;i<brackets.size();i++){
            int curr=min(brackets[i][0],income);
            ans += ((curr-prev)*brackets[i][1]/100.0);

            if(brackets[i][0]>=income) break;
            prev=brackets[i][0];
        }
        return ans;
    }
};
