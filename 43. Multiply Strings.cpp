class Solution {
public:
    /*
      16 
    X 15 
     240 

    0 0 3 0 -> 6*5
    0 0 9 0 -> 6*1
    0 1 4 0 -> 1*5
    0 2 4 0 -> 1*1
    */
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0" ; 
        int n = num1.size() , m = num2.size() , digit = n+m; 
        //at max digit will be n+m when multiplying n digit * m digit number
        vector<int>product(digit,0) ; 
        string ans = "";

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0') ; 
                int sum = product[i+j+1] + mul ; // add product[i+j+1] to keep track of prev contribution
                product[i+j+1] = sum%10; //multiplication step 
                product[i+j] = product[i+j] + sum/10 ; //carry step 
            /*    for(auto&it:product){
                    cout<<it<<" ";
                }
                cout<<"\n";
            */
            }
        }
        
        //SKIP LEADING ZEROS 
        int pos=0;
        while(pos<digit && product[pos]==0){
            pos++;
        }
        while(pos<digit){
            ans+=to_string(product[pos++]);
        }
        return ans;
    }
};
