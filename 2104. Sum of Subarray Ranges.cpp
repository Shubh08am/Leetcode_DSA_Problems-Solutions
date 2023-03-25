class Solution {
public:
    //Tried hard today was not able to do 
    //Just,came up with logic to use stack 
    vector<int> prevSmallerElement(vector<int> nums,int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);

        for(int i = 0; i < n;i++){
            while(s.top() != -1 && nums[s.top()] >= nums[i])
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> nums,int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);

        for(int i = n - 1; i >= 0;i--){
            while(s.top() != -1 && nums[s.top()] > nums[i])
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevGreaterElement(vector<int> nums,int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);

        for(int i = 0; i < n;i++){
            while(s.top() != -1 && nums[s.top()] <= nums[i])
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
    }
    vector<int> nextGreaterElement(vector<int> nums,int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);

        for(int i = n - 1; i >= 0;i--){
            while(s.top() != -1 && nums[s.top()] < nums[i])
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    } 

    long long subArrayRanges(vector<int>& nums) {
       int n = nums.size();
       long long ans = 0;

        vector<int> prevMin = prevSmallerElement(nums,n);
        vector<int> nextMin = nextSmallerElement(nums,n);
        vector<int> prevMax = prevGreaterElement(nums,n);
        vector<int> nextMax = nextGreaterElement(nums,n);


        for(int i = 0; i < nums.size();i++){
            //last element no next min or max
            if(nextMin[i] == -1){
                nextMin[i] = n;
            }
            if(nextMax[i] == -1){
                nextMax[i] = n;
            }

            long long int lmn = i - prevMin[i]; 
            long long int rmn = nextMin[i] - i;
            long long int lmx = i - prevMax[i] ;
            long long int rmx = nextMax[i] - i;
            ans += ( lmx * rmx - lmn * rmn ) * nums[i];
        }

        return ans;
    }
};
