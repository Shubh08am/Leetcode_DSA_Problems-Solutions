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
