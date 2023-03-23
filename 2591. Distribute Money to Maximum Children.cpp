class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)  return -1;
        money-=children;
        int num=money/7;
        if(num>children)    return children-1;
        if(num==children)   return children-(money%7!=0);
        if(num==children-1){
            int left=money-num*7;
            if(left==3) return max(0,children-2);
            return children-1;
        }
        return num;
        
        
        
    }
};
