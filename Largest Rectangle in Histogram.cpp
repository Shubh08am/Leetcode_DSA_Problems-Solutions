class Solution {
    private:
    vector<int>nextSmallerElement(vector<int>&smaller,int n){
        stack<int>s;
        s.push(-1) ; 
        vector<int>res(n);
        
        for(int i=n-1; i>=0 ; --i){
            int curr = smaller[i] ; 
            while(s.top()!=-1 and smaller[s.top()]>=curr){
                s.pop();
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }
 
    vector<int>prevSmallerElement(vector<int>&smaller,int n){
        stack<int>s;
        s.push(-1) ; 
        vector<int>res(n);
        
        for(int i=0; i<n ; i++){
            int curr = smaller[i] ; 
            while(s.top()!=-1 and smaller[s.top()]>=curr){
                s.pop();
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }    
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = INT_MIN ;
        
        vector<int>next(n) ; 
        vector<int>prev(n) ;
        
        next = nextSmallerElement(heights,n) ;
        prev = prevSmallerElement(heights,n) ;
        
        for(int i=0;i<n;i++){
            int l = heights[i] ; 
            
            
            //edge case
            if(next[i]==-1) {
                next[i]=n;
            }
            int b = next[i]-prev[i]-1 ;
            int new_area = l*b ; 
            area = max(area,new_area);
        }
        return area;
    }
};

// OTHER APPRAOCH 

class Solution {
public: 
/*
Time Complexity: O( N ) + O (N)
Space Complexity: O(N)
//SINGLE PASS :- OPTIMIZED APPROACH
*/
    int largestRectangleArea2(vector<int>& heights){
        //DOING ONE MORE ITERATION FOR LEFT VALUE IN STACK i.e till n [0 to n -> n+1 iteration]
        //SINGLE PASS FOR FINDING BOTH leftSmall & rightSmall 
        int n = heights.size() ,maxArea=0; 
        stack<int>s; // stores index

        for(int i=0;i<=n;i++){
            //if at last index we pop them and compute area for them  
            while(!s.empty() && (i==n || heights[s.top()] >= heights[i])){
  
           //FINDING THE HEIGHT USING INDEX FROM STACK TOP 
           int height = heights[s.top()] ; 
           s.pop(); //greater than or equal to element removed from stack after finding height of current element 
           
          //FINDING WIDTH 
           int width;
          //IF STACK IS EMPTY THAT MEANS LEFTSMALL IS 0 AS NO PREVIOUS ELEMENT FOR CURRENT ELEMENT(stack top)
          //IN THAT CASE WIDTH CONTRIBUTION IS DONE BY RIGHTSMALL ONLY 
          if(s.empty()){
              width=i; 
          }
          else{
              //BOTH LEFTSMALL AND RIGHTSMALL EXIST 
              int LEFTSMALL = s.top() ; //PREVIOUS ELEMENT OF CURRENT ELEMENT(stack top) AS WE POPPED ONCE
                                        // PREVIOUS ELEMENT IS ON TOP

             int RIGHTSMALL = i ; 

             width = RIGHTSMALL-LEFTSMALL-1; 
          }
            maxArea=max(maxArea,width*height);                    
        }
        //WHEN heights[s.top()] < heights[i] i.e greater element push its index in stack 
        s.push(i) ;
        }
    return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
     
     return largestRectangleArea2(heights);
/*
    Time Complexity: O(N) [Overall]
    Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array
    Multiple Pass [2 for calculating leftSmall and rightSmall]
*/
        int n = heights.size() ; 
        vector<int>leftSmall(n);
        vector<int>rightSmall(n);
        stack<int>s; // stores index

      //first computing leftsmall :- TC = O(N)[FOR TRAVERSAL] + O(N) [FOR STACK]
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop(); //greater than or equal to element removed from stack
            }

            //WHEN STACK EMPTY TAKE LEFT EXTREME I.E 0 AS LEFTSMALL 
            if(s.empty()){
                leftSmall[i]=0;
            }
            else{
                leftSmall[i]=s.top()+1;
            }
            s.push(i); //PUSH EVERY TIME INDEX IN STACK 
        }

         //USING SAME STACK AGAIN 
         //THEREFORE , CLEAR STACK NOW 
         
         while(!s.empty()){
              s.pop();
         }
         
        //Now computing rightSmall start from right i.e back ->TC = O(N)[FOR TRAVERSAL] + O(N) [FOR STACK]
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop(); //greater than or equal to element removed from stack
            }

            //WHEN STACK EMPTY TAKE RIGHT EXTREME I.E n-1 AS LEFTSMALL 
            if(s.empty()){
                rightSmall[i]=n-1;
            }
            else{
                rightSmall[i]=s.top()-1;
            }
            s.push(i); //PUSH EVERY TIME INDEX IN STACK 
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            int width = rightSmall[i]-leftSmall[i]+1; 
            int height = heights[i] ; 
            maxArea=max(maxArea,width*height);
        }
        return maxArea;
    }
};
