/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger>s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        for(int i=sz-1;i>=0;i--){
            s.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = s.top().getInteger();
        s.pop();
        return res;
    }
    
    bool hasNext() {
        while(!s.empty()){
            NestedInteger obj = s.top() ; 
            if(obj.isInteger()){
                return true;
            }
            else{       
                s.pop() ; 
                vector<NestedInteger>currList= obj.getList() ; 
                int sz = currList.size();
                for(int i=sz-1;i>=0;i--){
                    s.push(currList[i]);
                }
            }
        }
    return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
