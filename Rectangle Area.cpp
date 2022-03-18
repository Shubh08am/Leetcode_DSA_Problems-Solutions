class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int ta = ( ax2 - ax1 ) * ( ay2 - ay1 ) + ( bx2 - bx1) *(by2 - by1 ) ; 
        
        if ( ax2 <= bx1 || ax1 >= bx2 || by1 >= ay2 || by2 <= ay1 ) 
        { return ta ;}
        
        else{ 
            int m = min(ax2,bx2) - max(ax1 , bx1 );
            int n = min(ay2,by2) - max(ay1,by1);
            int tt = ta-(m*n);
            
            return tt;
        }
    }
};
