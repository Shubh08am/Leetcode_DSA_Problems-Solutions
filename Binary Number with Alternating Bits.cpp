class Solution {
public:
    bool hasAlternatingBits(int n) {
       int c = n %2;
        n /= 2;
        
        while (n>0) {
            if (c ==n %2)
                return false;
            c =n %2;
           n /= 2;
        }
        return true;

    }
};
