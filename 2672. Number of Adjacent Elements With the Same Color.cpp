class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        //adjacent element need to be equal and greater than 0 at the same time 
        vector<int>ans,color(n,0);
        int m = queries.size();
        int equalElem = 0 ;

        
        for(int i=0;i<m;i++){
            int pos = queries[i][0] , value = queries[i][1];
            
            //when recoloring decrease or increase the equalElem count if coloring with different color
            if(color[pos]>0){
            //when recoloring with same color do nothing
            if(color[pos]==value){
                ans.push_back(equalElem);
             }
            //when recoloring with different color 
                else{
                     //when recolored 
                   if(pos>0 && color[pos]!=0 && color[pos]==color[pos-1] && color[pos]!=value) equalElem--;
                   if(pos<n-1 && color[pos]!=0 && color[pos]==color[pos+1] && color[pos]!=value) equalElem-- ;
                    
                    //value is new color -> which is color at pos so see for adjacent
                   if(pos>0 && value!=0 && color[pos-1]==value) equalElem++;
                   if(pos<n-1 && value!=0 && color[pos+1]==value) equalElem++ ;
  
                     color[pos] = value ; 
                    ans.push_back(equalElem);
                }
            }
            
            //coloring for first time
            else{
             //at pos do coloring
            color[pos] = value ;         
            //Now,compare adjacent element and not equal to 0 case handled 
             // equal cases 
           if(pos>0 && color[pos]!=0 && color[pos]==color[pos-1]) equalElem++;
           if(pos<n-1 && color[pos]!=0 && color[pos]==color[pos+1]) equalElem++;       
           ans.push_back(equalElem);    
            }
            
         }
        return ans;
    }
};
