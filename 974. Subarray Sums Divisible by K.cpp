class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
 int ans=0;
 //prefix_sum logic
 for(int i=1;i<nums.size();i++){
 	nums[i]+=nums[i-1];
     }


     for(int i=0;i<nums.size();i++){
     cout<<nums[i]<<" ";	
     }
     cout<<"\n";

     //store remainder in nums now
     for(int i=0;i<nums.size();i++){
     nums[i]%=k;	
     	if(nums[i]<0){
         	nums[i]+=k;	
             	nums[i]%=k;
                 	}

                         }

                         for(int i=0;i<nums.size();i++){
                         cout<<nums[i]<<" ";	
                         }
                         cout<<"\n";
                         map<int,int>mp;
                         mp[0]=1;
                         for(int i=0;i<nums.size();i++){
                         	if(mp[nums[i]]>0){
                             	ans+=mp[nums[i]];	
                                 	}
                                     mp[nums[i]]++;	
                                     }

                                     return ans;
                                            
    }
};
