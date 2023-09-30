class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     /*
    i<j<k 
    nums[i] < nums[k] < nums[j] 
    break in 2 condition 
    [1] nums[i] < nums[k] 
    [2] nums[k] < nums[j] 

    i.e nums[k] is common 
    use monotonic decreasing stack 
    top of stack represents nums[k] 

    if curr_number is smaller than top of stack first condition satisfied 
    if curr_number is larger than top of stack second condition satisfied but top of stack will 
    be the candidate of third number and curr_num behaves as second_num
    */   
    int n = nums.size() ; 
    int third_num = INT_MIN ; 
    stack<int>s; 
    for(int i=n-1;i>=0;i--){
        int curr_num = nums[i] ; 
        //first condition 
        if(curr_num < third_num){
            return true;
        }
        //second condition 
        while(!s.empty() && curr_num > s.top()){
            third_num = s.top() ; 
            s.pop() ;
        }
        s.push(curr_num);
    }
    return false;
    }
};
