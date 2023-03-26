class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int>nge;  
    unordered_map<int,int> m;    
 		//just nge logic and use mapping for required no. 
     stack<int> s;
    int n=nums2.size();
    s.push(nums2[n-1]);  

    m[nums2[n-1]]=-1; //last element doesn't has nge 

    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()<nums2[i]){
         s.pop();
        }
            
        if(!s.empty()) { 
            m[nums2[i]]=s.top();
            }
        else if(s.empty()) {
            m[nums2[i]]=-1;
            }
        s.push(nums2[i]);
    }
  
    for(auto it : nums1)  nge.push_back(m[it]);
    return nge;   
    }
}; 
 
