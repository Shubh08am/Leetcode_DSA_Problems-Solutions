class Solution {
public:
    string getPermutation(int n, int k) {
        //first find fact for division of blocks
        vector<int>numbers;
        int fact=1;
        for(int i=1;i<n;i++){
        fact*=i;	
        numbers.push_back(i);	
    }

    numbers.push_back(n); 
    string res="";
    k=k-1;//as 0 based indexing

    while(true){
        
        res=res+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            
            if(numbers.size()==0){break;}
        k%=fact;
        fact/=numbers.size();

    }


    return res;     
    }
};
