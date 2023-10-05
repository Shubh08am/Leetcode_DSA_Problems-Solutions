class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),palindrome=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false)); 
        /*ALL LOWER DIAGONAL ELEMENTS ARE NOT PALINDROME AS ROW>COL I.E NO SUB-STRING 
        CASE-1 ALL DIAGONAL ELEMENTS ARE PALINDROME AS ROW==COL
        ALL UPPER DIAGONAL ELEMENTS MAY OR MAY NOT BE A PALINDROME 
        CASE-2 IF 2 LENGTH STRING I.E GAP=1 THAN COMPARE EXTREMES 
    CASE-3 IF >2 LENGTH STRING THAN COMPARE EXTREMES AND FOR S[ROW+1,COL-1] USE LOWER DIAGONAL ONE 
        I.E DP[ROW+1,COL-1] AS IT REPRESENTS STRING FROM S[ROW+1,COL-1]
        */ 
        for(int gap=0;gap<n;gap++){
            //start at first row i.e 0 
            int row=0,col=gap;
            //end at last column i.e n 
            while(col<n){
                //CASE-1 -> ONE LENGTH STRING 
                if(gap==0){
                    dp[row][col]=true;
                }
                //CASE-2 -> TWO LENGTH STRING 
                else if(gap==1){
                    dp[row][col]=s[row]==s[col];
                }
                //CASE-3 -> GREATER THAN TWO LENGTH STRING 
                else{
                    //FIRST COMPARE EXTREMES 
                    if(s[row]==s[col]){
                        //NOW SEE FOR LEFT STRING USING LOWER DIAGONAL 
                        dp[row][col]=dp[row+1][col-1];
                    }
                    else{
                        dp[row][col]=false;
                    }
                }
                palindrome+=dp[row][col];
                row++;col++;
            }
        }
    return palindrome;
    }
};
