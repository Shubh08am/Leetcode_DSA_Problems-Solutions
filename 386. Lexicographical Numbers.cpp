class Solution {
public:
//1 10-19 100-199  ...
//2 20-29 200-299  ... 
//3 30-39 300-399  ... 
//... so on to 9 

//includes all cases 
void number(int start , int n , vector<int>&ans){
if(start>n){
    return;
}
//1 10 100 1000  so on
//2 20 200 2000 so on
ans.push_back(start);
number(start*10,n,ans);

//remaining 11 to 19 || 21-29 || 31-39 so on... pushed 
if(start%10!=9) number(start+1,n,ans);
}
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        number(1,n,ans);
        return ans;
    }
};
