class Solution {
public:  
    string complexNumberMultiply(string num1, string num2) {
        // (a+ib)*(c+id) =ac−bd+i(bc+ad)   
        // 0 - +
        int pos1=num1.find('+');
        int a=stoi(num1.substr(0,pos1+1));
        //pos1 - i1
        int i1=num1.find('i');
        int b=stoi(num1.substr(pos1+1,i1+1));
        // 0 - +
        int pos2=num2.find('+');
        int c=stoi(num2.substr(0,pos2+1));
         //pos2 - i2
        int i2=num2.find('i');
        int d=stoi(num2.substr(pos2+1,i2+1));
        
        int real = (a*c - b*d);
        int img = (b*c + a*d);
        
        return to_string(real)+"+"+to_string(img)+"i";
    }
};
