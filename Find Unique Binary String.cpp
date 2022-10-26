class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums.size();
        string s="";
        for (int i = 0; i < n; ++i)
        {
            s+=nums[i][i] ^ 1;
        }
        return s;
    }
};
