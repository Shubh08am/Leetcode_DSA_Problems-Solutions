/* Jai Chhati Maya

Intuition
Since,we know that two strings are anagrams when they have all character same and in same frequency.So, we use this fact only and make use of some data structures to store our answer and make use of sort function so that we can easily make sure that two strings are anagrams than.

Approach
we will sort each strings in given strs than we will use vector of pairs to pair the string in sorted order with its original string.Than, we will iterate in vector of pairs and see if current value is equal to next value(use First for that) if yes we will take it in our answer(use Second for that) and later on add it in final results.
Go through the code part it is well explained.

Dry Run
Do, a dry run for cases to understand it more easily.

*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<string>sorted_strs;
      vector<vector<string>>groupOfAnagrams;
      vector<pair<string,string>>vp;

      for(int i=0;i<strs.size();i++){
          string curr = strs[i];
          string curr_copy = strs[i];
    
          sort(curr.begin(),curr.end()) ;
          vp.push_back({curr,curr_copy});
      }  
  
  // vp contains first sorted order one string and than original string --> use original

  sort(vp.begin(),vp.end()) ;
 /* For Debugging
 for(auto it:vp){
     cout<<it.first<<" "<<it.second<<"\n";
 } 
 cout<<endl;
*/
for(int i=0;i<vp.size()-1;i++){
    string current = vp[i].first ; 
    string next = vp[i+1].first;

   // cout<<current<<" "<<next<<endl;

    if(current==next){
        sorted_strs.push_back(vp[i].second) ;
    }
    else if(current!=next){
    /*   for(auto it:sorted_strs){
     cout<<it<<"\n";
 } */

       if(sorted_strs.size()==0){
           vector<string>nonequal;
           nonequal.push_back(vp[i].second);
           groupOfAnagrams.push_back(nonequal);
           nonequal.clear();
       }
      
    else{
        sorted_strs.push_back(vp[i].second);
        groupOfAnagrams.push_back(sorted_strs);
        sorted_strs.clear();
    }
    }
}
//for left pair of anagrams
sorted_strs.push_back(vp[vp.size()-1].second);
 groupOfAnagrams.push_back(sorted_strs);

return groupOfAnagrams;
    }
};
