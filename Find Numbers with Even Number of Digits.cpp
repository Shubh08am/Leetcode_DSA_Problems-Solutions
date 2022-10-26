class Solution {
public:

  int even_length(int n) { 
      string s = to_string(n);
      return s.size()&1;
}

int findNumbers(vector<int>& nums) { 
    int count=0; 
    for (auto&it:nums) { 
        if(!even_length(it)) count++; 
    }

return count;      
    }
};
