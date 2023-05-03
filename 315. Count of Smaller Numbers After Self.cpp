class Solution {
public:
    // INVERSION COUNT USING MERGE SORT 
    void merge(int start,int end,int mid,vector<int>&nums,vector<pair<int,int>>&vp,vector<pair<int,int>>&dummy,vector<int>&result){
         int inversion=0;
        int i=start,j=mid+1,k=start; 

        while(i<=mid&&j<=end){
             if(vp[i]<vp[j]){
                 //take in count no of inversion so far
                result[vp[i].second]+=inversion;
                dummy[k++]=vp[i++];
             }
             else if(vp[i]>vp[j]){
                 dummy[k++]=vp[j++];
                 //see for inversion as arr[i]>arr[j]
                 inversion++;
             }
          /*  else{
                dummy[k++]=vp[j++];
                dummy[k++]=vp[i++];
             }*/
        }
        while(i<=mid){
             result[vp[i].second]+=inversion;
            dummy[k++]=vp[i++];
        }
         while(j<=end){
            dummy[k++]=vp[j++];
        }
        for(int i=start;i<=end;i++) vp[i]=dummy[i];
      }
    void merge_sort(int start,int end,vector<int>&nums, vector<pair<int,int>>&vp,vector<pair<int,int>>&dummy,vector<int>&result){
        if(start>=end) return; 

        int mid = start+(end-start)/2;

        merge_sort(start,mid,nums,vp,dummy,result);//for left half 
        merge_sort(mid+1,end,nums,vp,dummy,result);//for right half 
        //merge them 
        merge(start,end,mid,nums,vp,dummy,result);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vp,dummy;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        dummy=vp;
        merge_sort(0,n-1,nums,vp,dummy,result);
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
