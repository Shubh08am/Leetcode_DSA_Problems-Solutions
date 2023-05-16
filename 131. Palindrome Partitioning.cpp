class Solution {
public: 
    bool isplaindrome(string s , int start , int end){
        while(start<=end){
            if(s[start]!=s[end]) return 0;
            start++;end--;
        }
        return 1;
    } 
    void partition(int start_index ,string s,vector<string>&pal,vector<vector<string>>&ans){
        //base case when reached at last position 
        int n=s.size();
        if(start_index==n) {
            ans.push_back(pal);
            return;
        }
        //try partition if that part is palindrome 
        for(int i = start_index ; i< n ; i++){
            //check for palindrome from start_index to i everytime 
            if(isplaindrome(s,start_index,i)){
                string sub = s.substr(start_index,i-start_index+1) ; 
                pal.push_back(sub);
                //call for next time 
                partition(i+1,s,pal,ans);
                //backtracking step 
                pal.pop_back();//remove the last partition done
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //backtracking 
        vector<vector<string>>ans;
        vector<string>pal;
        partition(0,s,pal,ans);
        return ans;
    }
}; 
