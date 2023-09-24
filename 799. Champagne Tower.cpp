class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //keep track of currRow_champagne and currRow_champagne  
        // 1 -> 0.5 + 0.5 
        // 0.5 -> 0.25 + 0.25 
        // O(query_row*query_row)

        //initially, all champagne poured at first glass
        vector<double>currRow_champagne(1,poured); 

        for(int i=0;i<=query_row;i++){
             vector<double>nextRow_champagne(i+2,0.0);
                for(int j=0;j<=i;j++){
                    //when overflow
                    if(currRow_champagne[j]>1.0){
                        // j -> j and j+1 flow takes place 
                        nextRow_champagne[j]+=(currRow_champagne[j]-1.0)/2.0;
                        nextRow_champagne[j+1]+=(currRow_champagne[j]-1.0)/2.0;
                        //now, currRow_champagne has only 1 glass of champagne 
                        currRow_champagne[j]=1;
                    }
                }
            if(i!=query_row)    currRow_champagne=nextRow_champagne;
        }
    return currRow_champagne[query_glass];
    }
};
