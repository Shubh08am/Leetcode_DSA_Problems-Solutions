class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       /* vector<int>positive,negative,result;
        for(auto&it:nums){
            if(it<0) negative.push_back(it);
            else positive.push_back(it);
        }
        for(int i=0;i<positive.size();i++){
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }
        return result;
        
        */
        
vector<int> answer(nums.size());
int positive = 0;    
int negative = 1;

    for(int i=0;i<nums.size();i++){
    if(nums[i]>0){
        answer[positive]=nums[i]; 
        positive+=2; 
    }
    else{
        answer[negative]=nums[i];
        negative+=2; 
    }   
}
return answer;
    }
};
