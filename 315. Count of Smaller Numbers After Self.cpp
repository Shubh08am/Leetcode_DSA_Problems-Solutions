class Solution {
public:
    // INVERSION COUNT USING MERGE SORT 
    void merge(int start,int end,int mid,vector<int>&nums,vector<pair<int,int>>&vp,vector<int>&result){
        vector<pair<int,int>>dummy(end-start+1);

        int i=start,j=mid+1,k=0; 

        while(i<=mid&&j<=end){
            //SORTING IN DESCENDING ORDER
            if(vp[i].first<=vp[j].first){
                dummy[k]=vp[j];
                j++;k++;
            }
            else{
                 dummy[k]=vp[i];
                //include inversions as i<j && arr[i]>arr[j]
                 result[vp[i].second]+=end-j+1;
                 i++;k++;
            }
        }
        while(i<=mid){
            dummy[k]=vp[i];
            i++;k++;
        }
         while(j<=end){
            dummy[k]=vp[j];
            j++;k++;
        }
        for(int i=start;i<=end;i++) vp[i]=dummy[i-start];
      }
    void merge_sort(int start,int end,vector<int>&nums, vector<pair<int,int>>&vp,vector<int>&result){
        if(start>=end) return; 

        int mid = start+(end-start)/2;

        merge_sort(start,mid,nums,vp,result);//for left half 
        merge_sort(mid+1,end,nums,vp,result);//for right half 
        //merge them 
        merge(start,end,mid,nums,vp,result);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vp;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        merge_sort(0,n-1,nums,vp,result);
        return result;
    }
};


/*
 // FOR INVERSION COUNT
int merge(int start,int end,int mid,vector<int>&nums,vector<int>&temp){
         int inversion_count=0;

        int i=start,j=mid,k=start; 

        while(i<=mid-1&&j<=end){
            if(nums[i]<=nums[j]){
                temp[k]=nums[i];
                i++;k++;
            }
            else{
                 temp[k]=nums[j];
                //include inversions as i<j && arr[i]>arr[j]
                inversion_count+=mid-i;
               // cout<<inversion_count<<" "<<i<<" "<<j<<" "<<k<<"\n";
                j++;k++;
            }
        }
        while(i<=mid-1){
            temp[k]=nums[i];
            i++;k++;
        }
         while(j<=end){
            temp[k]=nums[j];
            j++;k++;
        }
      //  for(int i=start;i<=end;i++) cout<<temp[i]<<" ";
     //   cout<<"\n";
        for(int i=start;i<=end;i++) nums[i]=temp[i];
        //  cout<<inversion_count<<" ";
        return inversion_count;
    }
    int merge_sort(int start,int end,vector<int>&nums,vector<int>&temp){
        if(start>=end) return 0; 
        int inversion_count=0;

        int mid = start+(end-start)/2;

        inversion_count+=merge_sort(start,mid,nums,temp);//for left half 
        inversion_count+=merge_sort(mid+1,end,nums,temp);//for right half 

        //merge them 
        inversion_count+=merge(start,end,mid+1,nums,temp);
       return inversion_count;
    }
    int inversion(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        int inversion_count = merge_sort(0,n-1,nums,temp);

        return inversion_count;
    }

*/
