class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size() ; 
        vector<string>ans;

        for(int i=0;i<n;i++){
            //TILL DIFFERENCE BETWEEN CONSECUTIVE ELEMENT IS 1 MOVE 
            //WHEN DIFFERECE >1 TAKE IN ANSWER ACCORDINGLY

            long long left_End = nums[i]  ;
 
            while(i<n-1 && nums[i+1]-1==nums[i]) i++;

            // TWO CASES 
            //CASE 1 ->
        //    [1,2,3,4] --> 1->4 [ANSWER]
       //     [1,2,4,5] --> 1->2 ,4->5 [ANSWER]
            //BREAK IN PATH IN BETWEEN 
            //ALL PATH INCLUDED 
            if(left_End != nums[i]){
                string path = to_string(left_End)+"->"+to_string(nums[i]);
                ans.push_back(path);
            } 
            
            //CASE 2 -> ONLY 1 POINT 
            else{
              //  cout<<left_End<<"\n";
                ans.push_back(to_string(left_End));
            }
        }
    return ans;
    }
};
