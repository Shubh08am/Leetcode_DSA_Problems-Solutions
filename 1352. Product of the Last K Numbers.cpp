class ProductOfNumbers {
public:
    vector<int>pre={1};

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0) pre={1};
      //prefix stored
         else {
           int value = pre.back()*num ;
           pre.push_back(value);
            } 
    }
    
    int getProduct(int k) {
        if(k>=pre.size()) return 0;
else
        return pre[pre.size()-1]/pre[pre.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
